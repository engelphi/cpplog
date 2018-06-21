#include <cpplog.hpp>
#include <date/date.h>

namespace cpplog {
constexpr char Logger::fmt_prefix_string[];

std::shared_ptr<ILoggingBackend> makeConsoleBackend() {
    return std::make_shared<internal::ConsoleLoggingBackend>();
}

std::string Logger::getTimestamp() const {
    using namespace date;
    auto timestamp = std::chrono::system_clock::now();
    std::stringstream ss;
    ss << timestamp;
    return ss.str();
}

std::string
Logger::severityToString(const cpplog::internal::severity level) const {
    switch (level) {
        case internal::severity::debug:
            return "DEBUG";
        case internal::severity::info:
            return "INFO";
        case internal::severity::warn:
            return "WARNING";
        case internal::severity::error:
            return "ERROR";
        case internal::severity::fatal:
            return "FATAL";
    }
    return "";
}

void Logger::setLoggingBackend(
    std::shared_ptr<ILoggingBackend> loggingBackend) {
    m_loggingBackend = loggingBackend;
}

} // namespace cpplog
