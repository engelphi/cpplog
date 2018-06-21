#pragma once
#include "../ILoggingBackend.hpp"

namespace cpplog::internal {
class ConsoleLoggingBackend : public ILoggingBackend {
  public:
    void write(const std::string &msg) override;
};

}
