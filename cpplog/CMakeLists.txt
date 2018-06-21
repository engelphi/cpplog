#add_library(libcpplog STATIC include/cpplog.hpp)
#target_include_directories(libcpplog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(libcpplog INTERFACE)
target_link_libraries(libcpplog INTERFACE date_interface fmt)
target_include_directories(libcpplog INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include) 

