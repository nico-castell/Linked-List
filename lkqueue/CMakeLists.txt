set(lib_name "lkqueue")

add_library(
    "${lib_name}" STATIC
    lkqueue.h
    lkqueue.cpp
)

target_include_directories("${lib_name}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
