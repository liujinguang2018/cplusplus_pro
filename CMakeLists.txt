cmake_minimum_required(VERSION 3.0)

project(cplusplus_pro)

MESSAGE(STATUS "==============================")

MESSAGE(STATUS "Operation System is ${CMAKE_SYSTEM}")

IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	MESSAGE(STATUS "current platform: Windows")  
	set(CMAKE_CXX_FLAGS "/EHsc ${CMAKE_CXX_FLAGS}")

	set(BUILD_USE_64BITS on)
	
	include_directories("D:/common-libs/boost_1_65_1")
	link_directories("D:/common-libs/boost_1_65_1/lib64-msvc-12.0")	
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
	MESSAGE(STATUS "current platform: cygwin")  
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	MESSAGE(STATUS "current platform: Linux")  	
ELSE ()
	MESSAGE(STATUS "current platform: UNIX")  
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Windows")

add_subdirectory(src)

