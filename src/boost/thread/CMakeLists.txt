


#find_library(LIBBOOST_THREAD_PATH boost_thread-vc120-mt-1_65_1 D:/common-libs/boost_1_65_1/lib64-msvc-12.0)
#IF(NOT LIBBOOST_THREAD_PATH)
#    MESSAGE(FATAL_ERROR "boost_thread lib not found")
#ENDIF(NOT LIBBOOST_THREAD_PATH)

#add_executable(thread_test_01 thread_test_01.cpp)
#target_link_libraries(thread_test_01 ${LIBBOOST_THREAD_PATH} ${LIBBOOST_TIMER_PATH} ${LIBBOOST_DATE_TIME_PATH})
#install(TARGETS thread_test_01 DESTINATION boost)

#add_executable(xtime xtime.cpp)
#target_link_libraries(xtime ${LIBBOOST_THREAD_PATH} ${LIBBOOST_TIMER_PATH} ${LIBBOOST_DATE_TIME_PATH})
#install(TARGETS xtime DESTINATION boost)

#add_executable(thread thread.cpp)
#target_link_libraries(thread ${LIBBOOST_THREAD_PATH} ${LIBBOOST_TIMER_PATH} ${LIBBOOST_DATE_TIME_PATH})
#install(TARGETS thread DESTINATION boost)

#add_executable(basic_atom basic_atom.cpp)
#target_link_libraries(basic_atom ${LIBBOOST_THREAD_PATH} ${LIBBOOST_TIMER_PATH} ${LIBBOOST_DATE_TIME_PATH})
#install(TARGETS basic_atom DESTINATION boost)

#add_executable(thread_with_paras thread_with_paras.cpp)
#target_link_libraries(thread_with_paras ${LIBBOOST_THREAD_PATH})
#install(TARGETS thread_with_paras DESTINATION boost)

add_library(boost_thread SHARED IMPORTED)
set_property(TARGET boost_thread  PROPERTY IMPORTED_LOCATION D:/common-libs/boost_1_65_1/lib64-msvc-12.0/boost_thread-vc120-mt-1_65_1.dll)
set_property(TARGET boost_thread  PROPERTY IMPORTED_IMPLIB D:/common-libs/boost_1_65_1/lib64-msvc-12.0/boost_thread-vc120-mt-1_65_1.lib)

add_executable(thread_with_paras thread_with_paras.cpp)
target_link_libraries(thread_with_paras ${boost_thread})
install(TARGETS thread_with_paras DESTINATION boost)

add_executable(basic_atom basic_atom.cpp)
target_link_libraries(basic_atom ${boost_thread})
install(TARGETS basic_atom DESTINATION boost)

