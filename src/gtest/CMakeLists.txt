add_executable(abs_test abs_test.cpp)
install(TARGETS abs_test DESTINATION gtest)
target_link_libraries(abs_test ${GTEST_LIB})

add_executable(examples_test examples_test.cpp)
install(TARGETS examples_test DESTINATION gtest)
target_link_libraries(examples_test ${GTEST_LIB})

#add_executable(thread_local_test thread_local_test.cpp)
#install(TARGETS thread_local_test DESTINATION c++11)

#add_executable(generic_progamming_test generic_progamming_test.cpp)
#install(TARGETS generic_progamming_test DESTINATION c++11)

#add_executable(shared_ptr_test shared_ptr_test.cpp)
#install(TARGETS shared_ptr_test DESTINATION boost)

#add_executable(shared_ptr_advanced_test shared_ptr_advanced_test.cpp pimpl_sample.cpp)
#install(TARGETS shared_ptr_advanced_test DESTINATION boost)