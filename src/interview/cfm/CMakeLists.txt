add_executable(conference_track_management_test main.cpp time_util.cpp talk.cpp track.cpp session.cpp conference.cpp)
install(TARGETS conference_track_management_test DESTINATION interview)


add_executable(time_util_test time_util_test.cpp time_util.cpp)
install(TARGETS time_util_test DESTINATION interview)
target_link_libraries(time_util_test ${GTEST_LIB})

add_executable(vector_usage_test vector_usage_test.cpp)
install(TARGETS vector_usage_test DESTINATION interview)
target_link_libraries(vector_usage_test ${GTEST_LIB})

