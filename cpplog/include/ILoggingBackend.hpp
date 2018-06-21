#pragma once
#include <string>
namespace cpplog {

class ILoggingBackend {
  public:
    virtual void write(const std::string &msg) = 0;
};
}
