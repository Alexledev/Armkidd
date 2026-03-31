#ifndef SERIAL_TRANSFER
#define SERIAL_TRANSFER

#include <rclcpp/rclcpp.hpp>
#include <libserial/SerialPort.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

class SerialTransfer
{
public:
    void open(std::string port, LibSerial::BaudRate baudRate)
    {
        serial.Open(port);
        serial.SetBaudRate(baudRate);
    }

    ~SerialTransfer()
    {
        serial.Close();
    }

    void close()
    {
        serial.Close();
    }

    void flush()
    {
        serial.DrainWriteBuffer();
    }

    void write(std::string msg)
    {
        serial.Write(msg);
    }

    void write(const std::vector<float>& vec)
    {  
        LibSerial::DataBuffer buffer;
        buffer.reserve(vec.size() * sizeof(float));

        for (float f : vec) {
            uint8_t bytes[sizeof(float)];
            std::memcpy(bytes, &f, sizeof(float));
            buffer.insert(buffer.end(), bytes, bytes + sizeof(float));
        }
        
        try {
            serial.Write(buffer);
        } catch (const std::exception &e) {
            RCLCPP_ERROR(rclcpp::get_logger("SerialTransfer"), "Serial write failed: %s", e.what());
        }

    }

    void write(const std::vector<double>& vec)
    {  
        LibSerial::DataBuffer buffer;
        buffer.reserve(vec.size() * sizeof(double));

        for (double f : vec) {
            uint8_t bytes[sizeof(double)];
            std::memcpy(bytes, &f, sizeof(double));
            buffer.insert(buffer.end(), bytes, bytes + sizeof(double));
        }

        // RCLCPP_INFO_STREAM(rclcpp::get_logger("ArmkiddInterface"),  "Sending " << buffer.size() << " bytes: "
        //     << std::accumulate(buffer.begin(), buffer.end(), std::string(),
        //     [](std::string a, uint8_t b){ return std::move(a) + " " + std::to_string(b); }));
        try {
            serial.Write(buffer);
        } catch (const std::exception &e) {
            RCLCPP_ERROR(rclcpp::get_logger("SerialTransfer"), "Serial write failed: %s", e.what());
        }

    }

    void write(const std::vector<std::vector<float>>& mat)
    {  
        LibSerial::DataBuffer buffer;
        for (const auto& row : mat)
        {
            for (float f : row)
            {
                uint8_t bytes[sizeof(float)];
                std::memcpy(bytes, &f, sizeof(float));
                buffer.insert(buffer.end(), bytes, bytes + sizeof(float));
            }
        }
        try {
            serial.Write(buffer);
        } catch (const std::exception &e) {
            RCLCPP_ERROR(rclcpp::get_logger("SerialTransfer"), "Serial write failed: %s", e.what());
        }

    }

    bool read_msg(std::string& input)
    {  
        if (serial.IsDataAvailable())
        {
            serial.ReadLine(input, '\n', 200);           
            input.erase(std::remove(input.begin(), input.end(), '\r'), input.end());
            input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
            return true;
        }
        return false;
    }

private:
  LibSerial::SerialPort serial;
};

#endif // SERIAL_TRANSFER