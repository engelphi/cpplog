#include <cpplog.hpp>
#include <iostream>

int main(int argc, char **argv) {
    cpplog::Logger logger;
    logger.setLoggingBackend(cpplog::makeConsoleBackend());
    logger.log(ERROR, "Argument count: {}", argc);
    return 0;
}
