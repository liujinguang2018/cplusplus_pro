




#add_executable(timer_test test_scoped_ptr.cpp pimpl_sample.cpp)
add_executable(timer_test timer_test.cpp)
install(TARGETS timer_test DESTINATION boost/timer_test)
#install(TARGETS scoped_ptr_test DESTINATION boost/smart_ptr)