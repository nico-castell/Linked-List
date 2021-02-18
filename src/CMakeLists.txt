set(
    Sources
    main.cpp
    lklist-tests/lklist-tests.cpp
    lkqueue-tests/lkqueue-tests.cpp
    lkstack-tests/lkstack-tests.cpp
)

set( # Not used yet
    Headers
    lklist-tests/lklist-tests.h
    lkqueue-tests/lkqueue-tests.h
    lkstack-tests/lkstack-tests.h
)

add_executable("${PROJECT_NAME}" ${Sources})
target_link_libraries("${PROJECT_NAME}" PRIVATE lklist)
target_link_libraries("${PROJECT_NAME}" PRIVATE lkqueue)
target_link_libraries("${PROJECT_NAME}" PRIVATE lkstack)
