#include "Logger.hpp"

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("err: unable to open log file.");
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const std::string& operation) {
    if (logFile.is_open()) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        logFile << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << " - " << operation << std::endl;
    }
}
