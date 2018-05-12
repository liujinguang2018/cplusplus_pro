FIND_LIBRARY(GTEST_LIB gtest /usr/lib  /usr/local/lib)
IF(NOT GTEST_LIB)
MESSAGE(FATAL_ERROR “libgtest not found”)
ENDIF(NOT GTEST_LIB)

#add_subdirectory(boost)

#add_subdirectory(stl)

#add_subdirectory(c++11)

#add_subdirectory(thread)

add_subdirectory(interview)

#add_subdirectory(inside-object-model)

#add_subdirectory(gtest)

#add_subdirectory(alg)

#add_subdirectory(dp)