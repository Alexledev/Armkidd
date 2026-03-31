#ifndef UTILS
#define UTILS

#include <rclcpp/rclcpp.hpp>
#include <sstream>
#include "transmit_modal.h"

class Utils {
public: 
    static bool parseInt(std::string input, int& output)
    {
        std::stringstream ss(input);
        int n;
        ss >> n;

        if (!ss.fail()) {
            output = n;
            return true;
        }

        return false;
    }

    static  TransmitStates convertToTransmitState(std::string input)
    {
        int output;
        if (Utils::parseInt(input, output))
        {
            return static_cast<TransmitStates>(output);        
        }
        throw std::invalid_argument("Invalid input");
    }
};

#endif