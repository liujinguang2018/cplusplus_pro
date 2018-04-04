





add_executable(scoped_ptr_test scoped_ptr_test.cpp)
install(TARGETS scoped_ptr_test DESTINATION boost)

add_executable(scoped_array_test scoped_array_test.cpp)
install(TARGETS scoped_array_test DESTINATION boost)

add_executable(unique_ptr_test unique_ptr_test.cpp)
install(TARGETS unique_ptr_test DESTINATION boost)

add_executable(shared_ptr_test shared_ptr_test.cpp)
install(TARGETS shared_ptr_test DESTINATION boost)

add_executable(shared_ptr_advanced_test shared_ptr_advanced_test.cpp pimpl_sample.cpp)
install(TARGETS shared_ptr_advanced_test DESTINATION boost)