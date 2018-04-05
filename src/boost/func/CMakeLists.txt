add_executable(test_for_each test_for_each.cpp)
install(TARGETS test_for_each DESTINATION boost)

add_executable(test_ref test_ref.cpp)
install(TARGETS test_ref DESTINATION boost)

add_executable(test_ref2 test_ref2.cpp)
install(TARGETS test_ref2 DESTINATION boost)

add_executable(test_bind test_bind.cpp)
install(TARGETS test_bind DESTINATION boost)

add_executable(test_bind2 test_bind2.cpp)
install(TARGETS test_bind2 DESTINATION boost)

add_executable(test_bind3 test_bind3.cpp)
install(TARGETS test_bind3 DESTINATION boost)