#include <cpplog.hpp>
#include <iostream>

int main(int argc, char **argv) {
    cpplog::Logger logger;
    logger.setLoggingBackend(cpplog::makeFileBackend("./log"));

    for (int i = 0; i < 10000; i++) {
        logger.log(ERROR, "Argument count: {}", i);
    }
    return 0;
}
