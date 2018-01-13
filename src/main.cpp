#include <cpplog.hpp>
#include <iostream>

int main(int argc, char **argv) {
    cpplog::log(cpplog::severity::ERROR, "Argument count: {}", argc);
    return 0;
}
