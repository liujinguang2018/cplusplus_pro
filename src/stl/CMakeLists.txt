
#add_executable(example_test_01 example_test_01.cpp)
#install(TARGETS example_test_01 DESTINATION stl)

add_executable(advance_test advance_test.cpp)
install(TARGETS advance_test DESTINATION stl)

add_executable(uninitialized_copy_test uninitialized_copy_test.cpp)
install(TARGETS uninitialized_copy_test DESTINATION stl)


add_executable(uninitialized_fill_test uninitialized_fill_test.cpp)
install(TARGETS uninitialized_fill_test DESTINATION stl)

add_executable(temporary_buffer_test temporary_buffer_test.cpp)
install(TARGETS temporary_buffer_test DESTINATION stl)

add_executable(alg_find_test alg_find_test.cpp)
install(TARGETS alg_find_test DESTINATION stl)

add_executable(alg_find_if_test alg_find_if_test.cpp)
install(TARGETS alg_find_if_test DESTINATION stl)

add_executable(alg_adjacent_find_test alg_adjacent_find_test.cpp)
install(TARGETS alg_adjacent_find_test DESTINATION stl)

add_executable(alg_find_first_of_test alg_find_first_of_test.cpp)
install(TARGETS alg_find_first_of_test DESTINATION stl)

add_executable(alg_search_test alg_search_test.cpp)
install(TARGETS alg_search_test DESTINATION stl)

add_executable(alg_find_end_test alg_find_end_test.cpp)
install(TARGETS alg_find_end_test DESTINATION stl)

add_executable(alg_search_n_test alg_search_n_test.cpp)
install(TARGETS alg_search_n_test DESTINATION stl)

add_executable(alg_count_test alg_count_test.cpp)
install(TARGETS alg_count_test DESTINATION stl)

add_executable(func_plus_minus_test func_plus_minus_test.cpp)
install(TARGETS func_plus_minus_test DESTINATION stl)

add_executable(alg_for_each_test alg_for_each_test.cpp)
install(TARGETS alg_for_each_test DESTINATION stl)

add_executable(alg_equal_test alg_equal_test.cpp)
install(TARGETS alg_equal_test DESTINATION stl)

add_executable(alg_mismatch_test alg_mismatch_test.cpp)
install(TARGETS alg_mismatch_test DESTINATION stl)

add_executable(alg_lexicographical_compare_test alg_lexicographical_compare_test.cpp)
install(TARGETS alg_lexicographical_compare_test DESTINATION stl)

add_executable(alg_min_max_test alg_min_max_test.cpp)
install(TARGETS alg_min_max_test DESTINATION stl)
