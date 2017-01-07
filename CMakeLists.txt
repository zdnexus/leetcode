cmake_minimum_required(VERSION 3.6)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES test.cpp)
#set(SOURCE_FILES 2.AddTwoNumbers.cpp cpp_arrToList.h)
set(SOURCE_FILES 3.LongestSubstringWithoutRepeatingCharacters.cpp)
add_executable(LeetCode ${SOURCE_FILES})