#pragma once
#include <chrono>
#include <fmt/format.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>

#include "ILoggingBackend.hpp"
#include "internal/ConsoleLoggingBackend.hpp"
#include "severity.hpp"

// I hate doing this but there is no other way
#define DEBUG cpplog::internal::severity::debug, __LINE__, __FILE__, __func__
#define INFO cpplog::internal::severity::info, __LINE__, __FILE__, __func__
#define WARN cpplog::internal::severity::warn, __LINE__, __FILE__, __func__
#define ERROR cpplog::internal::severity::error, __LINE__, __FILE__, __func__
#define FATAL cpplog::internal::severity::fatal, __LINE__, __FILE__, __func__

namespace cpplog {

std::shared_ptr<ILoggingBackend> makeConsoleBackend();

class Logger {
  public:
    void setLoggingBackend(std::shared_ptr<ILoggingBackend> loggingBackend);

    template <class... Args>
    void log(const internal::severity level, int line, const char *file,
             const char *func, std::string fmt_string, Args &&... args) {
        auto timestamp = getTimestamp();
        log(fmt_prefix_string + fmt_string, timestamp, severityToString(level),
            line, file, func, args...);
    }

  private:
    template <class... Args>
    void log(std::string fmt_string, Args &&... args) {
        m_loggingBackend->write(fmt::format(fmt_string, args...));
    }

    std::string severityToString(const cpplog::internal::severity level) const;

    std::string getTimestamp() const;

  private:
    static constexpr char fmt_prefix_string[] =
        "[{} {}: line={}, file={}, func={}]:";

    std::shared_ptr<ILoggingBackend> m_loggingBackend{nullptr};
};

}  // namespace cpplog
