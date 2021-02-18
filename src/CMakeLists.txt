add_executable("${PROJECT_NAME}" main.cpp "lklist-tests/lklist-tests.cpp" "lkqueue-tests/lkqueue-tests.cpp" "lkstack-tests/lkstack-tests.cpp")
target_link_libraries("${PROJECT_NAME}" PRIVATE lklist)
target_link_libraries("${PROJECT_NAME}" PRIVATE lkqueue)
target_link_libraries("${PROJECT_NAME}" PRIVATE lkstack)
