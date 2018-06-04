
add_executable(composite_test composite.cpp component.cpp leaf.cpp main.cpp)
install(TARGETS composite_test DESTINATION dp)


