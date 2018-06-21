

file (GLOB SRCS src/*.cpp src/internal/*.cpp)
file (GLOB HEADERS include/*.hpp include/internal/*.hpp)

add_library(libcpplog STATIC ${SRCS} ${HEADERS})
target_link_libraries(libcpplog PUBLIC date_interface fmt)
target_include_directories(libcpplog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) 

