add_executable(conference_track_management_test main.cpp time_util.cpp talk.cpp track.cpp session.cpp conference.cpp)
install(TARGETS conference_track_management_test DESTINATION interview)


add_executable(unittest_time_util_test unittest_time_util_test.cpp time_util.cpp)
install(TARGETS unittest_time_util_test DESTINATION interview)
target_link_libraries(unittest_time_util_test ${GTEST_LIB})

add_executable(unittest_vector_usage_test unittest_vector_usage_test.cpp)
install(TARGETS unittest_vector_usage_test DESTINATION interview)
target_link_libraries(unittest_vector_usage_test ${GTEST_LIB})

