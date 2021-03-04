function(add_custom_test test_name linked_lib source_file)
	add_executable("${test_name}" "${source_file}")
	target_link_libraries(
		"${test_name}" PUBLIC
		"${linked_lib}"
		gtest
		gtest_main
	)
	gtest_discover_tests(
		"${test_name}"
	)
endfunction()

add_custom_test(
	LinkedListTests
	lklist
	lklist.cpp
)

add_custom_test(
	LinkedQueueTests
	lkqueue
	lkqueue.cpp
)

add_custom_test(
	LinkedStackTests
	lkstack
	lkstack.cpp
)
