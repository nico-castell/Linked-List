cmake_minimum_required(VERSION 3.16.3)
project(linked-list VERSION 1.0.1)

# Enable testing
#include(CTest)
include(GoogleTest)
enable_testing()

# Configure google tests and tests folder
# This cofig was found in: https://crascit.com/2015/07/25/cmake-gtest/
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(
	COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
	WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)
execute_process(
	COMMAND "${CMAKE_COMMAND}" --build .
	WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)
# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory(
	"${CMAKE_BINARY_DIR}/googletest-src"
	"${CMAKE_BINARY_DIR}/googletest-build"
)

# Use more warnings
if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra)
endif()

# Add all the project subdirectories
add_subdirectory(lklist)
add_subdirectory(lkqueue)
add_subdirectory(lkstack)
#add_subdirectory(src)
add_subdirectory(tests)

set(CPACK_PROJECT_NAME "${PROJECT_NAME}")
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
