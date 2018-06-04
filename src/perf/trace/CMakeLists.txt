add_executable(trace_test trace.cpp tracev2.cpp main.cpp)
install(TARGETS trace_test DESTINATION perf)

