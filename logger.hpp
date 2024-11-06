#pragma once

#include <fstream>
#include <chrono>
#include <iomanip>

#pragma warning (disable : 4996)

class Logger {
public:
    Logger(const std::string& filename);
    ~Logger();
    void log(const std::string& message);

private:
    std::ofstream logFile;
};