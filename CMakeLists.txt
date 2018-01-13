cmake_minimum_required(VERSION 3.9)
project(cpplog)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file (GLOB SRCS include/cpplog/SeverityLevel.cpp src/*.cpp)

add_executable(cpplog ${SRCS})
target_link_libraries(cpplog ${CONAN_LIBS})
target_include_directories(cpplog PUBLIC cpplog/include)


install (TARGETS cpplog DESTINATION bin)
