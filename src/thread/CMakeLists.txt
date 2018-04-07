add_executable(hello hello.cpp)
install(TARGETS hello DESTINATION thread)

add_executable(thread_mgmt_test01 thread_mgmt_test01.cpp)
install(TARGETS thread_mgmt_test01 DESTINATION thread)

add_executable(thread_mgmt_test02 thread_mgmt_test02.cpp)
install(TARGETS thread_mgmt_test02 DESTINATION thread)

add_executable(thread_mgmt_test03 thread_mgmt_test03.cpp)
install(TARGETS thread_mgmt_test03 DESTINATION thread)

add_executable(thread_mgmt_test04 thread_mgmt_test04.cpp)
install(TARGETS thread_mgmt_test04 DESTINATION thread)