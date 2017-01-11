cmake_minimum_required(VERSION 3.6)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

#测试文件
#set(SOURCE_FILES test.cpp)

#B-Tree
#set(SOURCE_FILES BTree/index.cpp BTree/tree.h)

#LeetCode
#set(SOURCE_FILES arrToList.h)
#set(SOURCE_FILES 2.AddTwoNumbers.cpp)
#set(SOURCE_FILES 3.LongestSubstringWithoutRepeatingCharacters.cpp)
#set(SOURCE_FILES 5.LongestPalindromicSubstring.cpp)

#指针
#set(SOURCE_FILES Pointer/Subject.cpp)
#set(SOURCE_FILES Pointer/1.Point.cpp)
#set(SOURCE_FILES Pointer/2.sizeof.cpp)

#基础知识
set(SOURCE_FILES Base/const.cpp)
#set(SOURCE_FILES Base/PointAndArray.cpp)

add_executable(LeetCode ${SOURCE_FILES})