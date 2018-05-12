
add_executable(bridge_test abstraction.cpp abstraction_imp.cpp main.cpp)
#target_link_libraries(thread_with_paras ${LIBBOOST_THREAD_PATH} ${LIBBOOST_SYSTEM_PATH})
install(TARGETS bridge_test DESTINATION dp)


