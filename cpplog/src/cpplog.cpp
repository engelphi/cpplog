#include "cpplog.hpp"
#include "internal/ConsoleLoggingBackend.hpp"
#include "internal/FileLoggingBackend.hpp"

#include <chrono>
#include <date/date.h>
#include <sstream>
namespace cpplog {
constexpr char Logger::fmt_prefix_string[];

std::shared_ptr<ILoggingBackend> makeConsoleBackend() {
    return std::make_shared<internal::ConsoleLoggingBackend>();
}

std::shared_ptr<ILoggingBackend> makeFileBackend(const std::string &file_path) {
    return std::make_shared<internal::FileLoggingBackend>(file_path);
}

std::string Logger::getTimestamp() const {
    using namespace date;
    auto timestamp = std::chrono::system_clock::now();
    std::stringstream ss;
    ss << timestamp;
    return ss.str();
}

std::string Logger::severityToString(const cpplog::internal::Severity level) const {
    switch (level) {
        case internal::Severity::debug:
            return "DEBUG";
        case internal::Severity::info:
            return "INFO";
        case internal::Severity::warn:
            return "WARNING";
        case internal::Severity::error:
            return "ERROR";
        case internal::Severity::fatal:
            return "FATAL";
    }
    return "";
}

void Logger::setLoggingBackend(
    std::shared_ptr<ILoggingBackend> loggingBackend) {
    m_loggingBackend = loggingBackend;
}

} // namespace cpplog
