cmake_minimum_required(VERSION 3.16.3)
project(linked-list VERSION 1.0.1)

# include(CTest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_subdirectory(lklist)
add_subdirectory(lkqueue)
add_subdirectory(lkstack)
# add_subdirectory(src)

add_subdirectory(googletest)
add_subdirectory(tests)

# set(CPACK_PROJECT_NAME "${PROJECT_NAME}")
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
