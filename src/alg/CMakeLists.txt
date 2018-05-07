add_executable(sll_test IntSLList_test.cpp IntSLList.cpp)
install(TARGETS sll_test DESTINATION alg)
target_link_libraries(sll_test ${GTEST_LIB})

add_executable(binary_search_tree  binary_search_tree_test.cpp)
install(TARGETS binary_search_tree DESTINATION alg)


#add_executable(thread_local_test thread_local_test.cpp)
#install(TARGETS thread_local_test DESTINATION c++11)

#add_executable(generic_progamming_test generic_progamming_test.cpp)
#install(TARGETS generic_progamming_test DESTINATION c++11)

#add_executable(shared_ptr_test shared_ptr_test.cpp)
#install(TARGETS shared_ptr_test DESTINATION boost)

#add_executable(shared_ptr_advanced_test shared_ptr_advanced_test.cpp pimpl_sample.cpp)
#install(TARGETS shared_ptr_advanced_test DESTINATION boost)