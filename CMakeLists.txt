cmake_minimum_required(VERSION 3.10)

project(cplusplus_pro)


include_directories("D:/common-libs/boost_1_65_1")

link_directories("D:/common-libs/boost_1_65_1/lib64-msvc-12.0")

#find_library(LIBBOOST_THREAD_PATH boost_thread-vc120-mt-1_65_1 D:/common-libs/boost_1_65_1/lib64-msvc-12.0)
#IF(NOT LIBBOOST_THREAD_PATH)
#    MESSAGE(FATAL_ERROR "boost_thread lib not found")
#ENDIF(NOT LIBBOOST_THREAD_PATH)

#find_library(LIBBOOST_TIMER_PATH boost_timer-vc120-mt-1_65_1 D:/common-libs/boost_1_65_1/lib64-msvc-12.0)
#IF(NOT LIBBOOST_TIMER_PATH)
#    MESSAGE(FATAL_ERROR "boost_timer lib not found")
#ENDIF(NOT LIBBOOST_TIMER_PATH)

#find_library(LIBBOOST_DATE_TIME_PATH boost_date_time-vc120-mt-1_65_1 D:/common-libs/boost_1_65_1/lib64-msvc-12.0)
#IF(NOT LIBBOOST_DATE_TIME_PATH)
#    MESSAGE(FATAL_ERROR "boost_date_time lib not found")
#ENDIF(NOT LIBBOOST_DATE_TIME_PATH)

set(CMAKE_CXX_FLAGS "/EHsc ${CMAKE_CXX_FLAGS}")

set(BUILD_USE_64BITS on)

add_subdirectory(src)

