#pragma once
#include "../ILoggingBackend.hpp"
#include <mutex>

namespace cpplog::internal {
class ConsoleLoggingBackend : public ILoggingBackend {
  public:
    void write(const std::string &msg) override;

  private:
    std::mutex m_mutex;
};

} // namespace cpplog::internal
