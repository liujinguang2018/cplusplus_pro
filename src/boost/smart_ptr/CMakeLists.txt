




add_executable(test_scoped_ptr test_scoped_ptr.cpp pimpl_sample.cpp)
install(TARGETS test_scoped_ptr DESTINATION boost/smart_ptr)