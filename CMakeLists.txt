cmake_minimum_required(VERSION 3.0)
project(Euler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (GTest_FOUND)
	include_directories(SYSTEM ${GTEST_INCLUDE_DIRS})
else()
	message(STATUS "Gtest not found")
endif(GTest_FOUND)

include_directories(euler)
add_subdirectory(euler)
add_subdirectory(problem21)
add_subdirectory(problem20)
