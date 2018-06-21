#pragma once
#include <fmt/format.h>
#include <string>

#include "ILoggingBackend.hpp"
#include "internal/Severity.hpp"

// I hate doing this but there is no other way
#define DEBUG cpplog::internal::Severity::debug, __LINE__, __FILE__, __func__
#define INFO cpplog::internal::Severity::info, __LINE__, __FILE__, __func__
#define WARN cpplog::internal::Severity::warn, __LINE__, __FILE__, __func__
#define ERROR cpplog::internal::Severity::error, __LINE__, __FILE__, __func__
#define FATAL cpplog::internal::Severity::fatal, __LINE__, __FILE__, __func__

namespace cpplog {

std::shared_ptr<ILoggingBackend> makeConsoleBackend();

std::shared_ptr<ILoggingBackend> makeFileBackend(const std::string &file_path);

class Logger {
  public:
    void setLoggingBackend(std::shared_ptr<ILoggingBackend> loggingBackend);

    template <class... Args>
    void log(const internal::Severity level, int line, const char *file, const char *func,
             const std::string &fmt_string, Args &&... args) const;

  private:
    template <class... Args>
    void log(const std::string &fmt_string, Args &&... args) const;

    std::string severityToString(const cpplog::internal::Severity level) const;

    std::string getTimestamp() const;

  private:
    static constexpr char fmt_prefix_string[] = "[{} {}: line={}, file={}, func={}]:";

    std::shared_ptr<ILoggingBackend> m_loggingBackend{nullptr};
};

template <class... Args>
void Logger::log(const std::string &fmt_string, Args &&... args) const {
    m_loggingBackend->write(fmt::format(fmt_string, args...));
}

template <class... Args>
void Logger::log(const internal::Severity level, int line, const char *file, const char *func,
                 const std::string &fmt_string, Args &&... args) const {
    log(fmt_prefix_string + fmt_string + "\n", getTimestamp(), severityToString(level), line, file,
        func, args...);
}

} // namespace cpplog
