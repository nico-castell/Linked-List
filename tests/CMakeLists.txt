cmake_minimum_required(VERSION 3.16.3)

set(test_name "LinkedListTests")

set(
    Sources
    lklist.cpp
)

add_executable("${test_name}" ${Sources})
target_link_libraries(
    "${test_name}" PUBLIC
    lklist
    gtest
    gtest_main
)

add_test(
    NAME "${test_name}"
    COMMAND "${test_name}"
)
