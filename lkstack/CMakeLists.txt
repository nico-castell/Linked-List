set(lib_name "lkstack")

add_library(
    "${lib_name}" STATIC
    lkstack.h
    lkstack.cpp
)

target_include_directories("${lib_name}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
