cmake_minimum_required(VERSION 3.6)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES test.cpp)
#set(SOURCE_FILES 二叉树/index.cpp 二叉树/tree.h)
#set(SOURCE_FILES arrToList.h)
#set(SOURCE_FILES 2.AddTwoNumbers.cpp)
#set(SOURCE_FILES 3.LongestSubstringWithoutRepeatingCharacters.cpp)
#set(SOURCE_FILES 5.LongestPalindromicSubstring.cpp)
set(SOURCE_FILES Pointer/1.Point.cpp)

add_executable(LeetCode ${SOURCE_FILES})