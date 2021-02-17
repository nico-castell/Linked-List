set(lib_name "lklist")

add_library(
  "${lib_name}" STATIC
  lklist.h
  lklist.cpp
)

target_include_directories("${lib_name}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
