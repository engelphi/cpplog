cmake_minimum_required(VERSION 3.9)
project(cpplog)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(third-party/fmt)
add_subdirectory(third-party/date)
add_subdirectory(cpplog)

add_executable(demo src/main.cpp)
target_link_libraries(demo PRIVATE libcpplog)
