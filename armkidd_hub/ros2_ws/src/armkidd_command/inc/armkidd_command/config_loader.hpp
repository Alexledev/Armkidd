#pragma once

#include <yaml-cpp/yaml.h>
#include <string>
#include <fstream>

class ConfigLoader
{
public:
    ConfigLoader(
        const std::string& root = "",
        const std::string& dir = "",
        const std::string& path = "../shared/config.yaml"
    )
        : root_(root), dir_(dir), path_(path)
    {
        cfg_ = YAML::LoadFile(path_);
    }

    template<typename T>
    T get(const std::string& name)
    {
        if (dir_.empty())
            return cfg_[root_][name].as<T>();

        return cfg_[root_][dir_][name].as<T>();
    }

    template<typename T>
    void set(const std::string& name, const T& value)
    {
        if (dir_.empty())
            cfg_[root_][name] = value;
        else
            cfg_[root_][dir_][name] = value;
    }

    void save()
    {
        std::ofstream fout(path_);
        fout << cfg_;
    }

    template<typename T>
    void setAndSave(const std::string& name, const T& value)
    {
        set(name, value);
        save();
    }

private:
    std::string root_;
    std::string dir_;
    std::string path_;
    YAML::Node cfg_;
};