add_executable(timer_test timer_test.cpp)
install(TARGETS timer_test DESTINATION boost)

add_executable(progress_timer_test progress_timer_test.cpp)
install(TARGETS progress_timer_test DESTINATION boost)

add_executable(progress_timer_extended_test progress_timer_extended_test.cpp)
install(TARGETS progress_timer_extended_test DESTINATION boost)

add_executable(progress_display_test progress_display_test.cpp)
install(TARGETS progress_display_test DESTINATION boost)

add_executable(date_test date_test.cpp)
install(TARGETS date_test DESTINATION boost)

add_executable(ptimer_test ptimer_test.cpp)
install(TARGETS ptimer_test DESTINATION boost)

add_executable(work_time work_time.cpp)
install(TARGETS work_time DESTINATION boost)

#add_executable(literal_test literal_test.cpp)
#install(TARGETS literal_test DESTINATION boost)