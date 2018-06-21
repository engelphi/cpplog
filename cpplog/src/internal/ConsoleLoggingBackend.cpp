#include <internal/ConsoleLoggingBackend.hpp>
#include <iostream>

namespace cpplog::internal {
void ConsoleLoggingBackend::write(const std::string &msg) {
    std::lock_guard lock{m_mutex};
    std::cout << msg << "\n";
}
} // namespace cpplog::internal
