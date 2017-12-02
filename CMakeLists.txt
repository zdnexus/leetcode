cmake_minimum_required(VERSION 3.6)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES arrToList.h)
#set(SOURCE_FILES 2.AddTwoNumbers.cpp)
#set(SOURCE_FILES 3.LongestSubstringWithoutRepeatingCharacters.cpp)
#set(SOURCE_FILES 5.LongestPalindromicSubstring.cpp)


#set(SOURCE_FILES 排序/swap.h)
#set(SOURCE_FILES 排序/1.BubbleSort.cpp)
#set(SOURCE_FILES 排序/2.SelectionSort.cpp)
#set(SOURCE_FILES 排序/3.InsertionSort.cpp)
#set(SOURCE_FILES 排序/4.ShellSort.cpp)
#set(SOURCE_FILES 排序/5.MergeSort.cpp)
#set(SOURCE_FILES 排序/6.QuickSort.cpp)
#set(SOURCE_FILES 排序/7.HeapSort.cpp)
#set(SOURCE_FILES 排序/8.BucketSort.cpp)
#set(SOURCE_FILES 排序/9.CountingSort.cpp)
#set(SOURCE_FILES 排序/10.RadixSort.cpp)
#set(SOURCE_FILES 排序/test.cpp)

set(SOURCE_FILES 基础/Array.cpp)

add_executable(LeetCode ${SOURCE_FILES})