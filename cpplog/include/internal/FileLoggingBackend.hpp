#pragma once
#include "../ILoggingBackend.hpp"
#include <fstream>
#include <mutex>

namespace cpplog::internal {
class FileLoggingBackend : public ILoggingBackend {
  public:
    FileLoggingBackend(const std::string &file_path);

    void write(const std::string &msg) override;

  private:
    std::ofstream m_stream;
    std::mutex m_mutex;
};
} // namespace cpplog::internal
