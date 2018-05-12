
add_executable(adapter_class_test adapter_class_main.cpp adapter_class.cpp)
#target_link_libraries(thread_with_paras ${LIBBOOST_THREAD_PATH} ${LIBBOOST_SYSTEM_PATH})
install(TARGETS adapter_class_test DESTINATION dp)

add_executable(adapter_object_test adapter_object_main.cpp adapter_object.cpp)
#target_link_libraries(thread_with_paras ${LIBBOOST_THREAD_PATH} ${LIBBOOST_SYSTEM_PATH})
install(TARGETS adapter_object_test DESTINATION dp)


