#pragma once
#include <chrono>
#include <date/date.h>
#include <fmt/format.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>

namespace cpplog {

enum class severity {
    EMERGENCY,
    ALERT,
    CRITICAL,
    ERROR,
    WARNING,
    NOTICE,
    INFO,
    DEBUG,
    LOG
};

namespace internal {

std::string fmt_prefix_string = "[{}]:[{}]:";

template <class ...Args>
void log(std::string fmt_string, Args&&... args) {
    std::clog << fmt::format(fmt_string, args...) << std::endl;
}

std::string get_timestamp() {
    using namespace date;
    auto timestamp = std::chrono::system_clock::now();
    std::stringstream ss;
    ss << timestamp;
    return ss.str();
}

const char *severity_to_string(const cpplog::severity level) {
    switch(level) {
        case severity::EMERGENCY: return "EMERGENCY";
        case severity::ALERT: return "ALERT";
        case severity::CRITICAL: return "CRITICAL";
        case severity::ERROR: return "ERROR";
        case severity::WARNING: return "WARNING";
        case severity::NOTICE: return "NOTICE";
        case severity::INFO: return "INFO";
        case severity::DEBUG: return "DEBUG";
        case severity::LOG: return "LOG";
    }
    return "";
}

}  // namespace internal

template <class ...Args>
void log(const severity level, std::string fmt_string, Args&&... args) {
    auto timestamp = internal::get_timestamp();
    internal::log(internal::fmt_prefix_string + fmt_string, timestamp,
                  internal::severity_to_string(level), args...);
}

}  // namespace cpplog
