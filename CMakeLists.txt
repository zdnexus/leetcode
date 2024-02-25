cmake_minimum_required(VERSION 3.6.3)

set(CMAKE_CXX_STANDARD 11)

project(leetCode)

add_executable(SOURCE_FILES 基础/test.cpp)

#add_executable(SOURCE_FILES 排序/swap.h)
#add_executable(SOURCE_FILES 排序/1.BubbleSort.cpp)
#add_executable(SOURCE_FILES 排序/2.SelectionSort.cpp)
#add_executable(SOURCE_FILES 排序/3.InsertionSort.cpp)
#add_executable(SOURCE_FILES 排序/4.ShellSort.cpp)
#add_executable(SOURCE_FILES 排序/5.MergeSort.cpp)
#add_executable(SOURCE_FILES 排序/6.QuickSort.cpp)
#add_executable(SOURCE_FILES 排序/7.HeapSort.cpp)
#add_executable(SOURCE_FILES 排序/8.BucketSort.cpp)
#add_executable(SOURCE_FILES 排序/9.CountingSort.cpp)
#add_executable(SOURCE_FILES 排序/10.RadixSort.cpp)

#add_executable(SOURCE_FILES arrToList.h)
#add_executable(SOURCE_FILES 2.AddTwoNumbers.cpp)
#add_executable(SOURCE_FILES 3.LongestSubstringWithoutRepeatingCharacters.cpp)
#add_executable(SOURCE_FILES 5.LongestPalindromicSubstring.cpp)

add_executable(leetCode ${SOURCE_FILES})
