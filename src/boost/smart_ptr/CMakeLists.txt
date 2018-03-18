




add_executable(test_scoped_ptr test_scoped_ptr.cpp pimpl_sample.cpp)
add_executable(scoped_ptr_test scoped_ptr_test.cpp)
add_executable(scoped_array_test scoped_array_test.cpp)
install(TARGETS test_scoped_ptr DESTINATION boost)
install(TARGETS scoped_ptr_test DESTINATION boost)
install(TARGETS scoped_array_test DESTINATION boost)