#include <internal/FileLoggingBackend.hpp>

namespace cpplog::internal {
FileLoggingBackend::FileLoggingBackend(const std::string &file_path) : m_stream(file_path) {}

void FileLoggingBackend::write(const std::string &msg) {
    std::lock_guard lock{m_mutex};
    m_stream << msg;
}
} // namespace cpplog::internal
