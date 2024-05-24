cmake_minimum_required (VERSION 3.10)

project(CPP-Core) # Set the project name


# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Set cmake output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin/)


# Third-party library
include(ExternalProject)
ExternalProject_Add(
    googletest
    PREFIX "${CMAKE_BINARY_DIR}/lib"
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "main"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/lib/installed
)
set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE) # Prevent build on all targets build


include(GNUInstallDirs) # Define ${CMAKE_INSTALL_...} variables
# Specify where third-party libraries are located
link_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_INCLUDEDIR})


# This is required for googletest
find_package(Threads REQUIRED)

# Add definition for library
add_library(binary_tree DataStructure/BinaryTree/binary_tree.cpp)
add_library(heap_sort Algorithms/HeapSort/heap_sort.cpp)
add_library(linked_list DataStructure/LinkedList/linked_list.cpp)
add_library(merge_sort Algorithms/MergeSort/merge_sort.cpp)
add_library(mrroot501_hash_table DataStructure/HashTable/mrroot501_hash_table.cpp)
add_library(segment_tree DataStructure/SegmentTree/segment_tree.cpp)
add_library(quick_sort Algorithms/QuickSort/quick_sort.cpp)


# Add targets for main program
add_executable(extra_long_factorial_main ProblemSolving/ExtraLongFactorial/main.cpp)
target_link_libraries(extra_long_factorial_main extra_long_factorial)

add_executable(merge_sort_external_main Algorithms/MergeSortExternal/main.cpp)
target_link_libraries(merge_sort_external_main merge_sort heap_sort)

add_executable(binary_tree_main DataStructure/BinaryTree/main.cpp)
target_link_libraries(binary_tree_main binary_tree gtest Threads::Threads)

add_executable(segment_tree_main DataStructure/SegmentTree/main.cpp)
target_link_libraries(segment_tree_main segment_tree)

add_executable(mrroot501_hash_table_main DataStructure/HashTable/main.cpp)
target_link_libraries(mrroot501_hash_table_main mrroot501_hash_table)

add_executable(linked_list_main DataStructure/LinkedList/main.cpp)
target_link_libraries(linked_list_main linked_list)

add_executable(quick_sort_main Algorithms/QuickSort/main.cpp)
target_link_libraries(quick_sort_main quick_sort)


# Add targets for testing
add_executable(test_extra_long_factorial ProblemSolving/ExtraLongFactorial/main.cpp)
target_link_libraries(test_extra_long_factorial gtest Threads::Threads)

add_executable(test_merge_sort Algorithms/MergeSort/test_merge_sort.cpp)
target_link_libraries(test_merge_sort merge_sort gtest Threads::Threads)

add_executable(test_heap_sort Algorithms/HeapSort/test_heap_sort.cpp)
target_link_libraries(test_heap_sort heap_sort gtest Threads::Threads)

add_executable(test_longest_common_subsequence ProblemSolving/LongestComonSubsequence/main.cpp)
target_link_libraries(test_longest_common_subsequence gtest Threads::Threads)

add_executable(test_longest_palindromic_substring ProblemSolving/LongestPalindromicSubstring/main.cpp)
target_link_libraries(test_longest_palindromic_substring gtest Threads::Threads)

add_executable(test_range_sum_queries_without_updates ProblemSolving/RangeSumQueriesWithoutUpdates/main.cpp)
target_link_libraries(test_range_sum_queries_without_updates gtest Threads::Threads)

add_executable(test_find_largest_value_in_tree_row ProblemSolving/FindLargestValueInTreeRow/main.cpp)
target_link_libraries(test_find_largest_value_in_tree_row binary_tree gtest Threads::Threads)

add_executable(test_shortest_path_in_binary_matrix ProblemSolving/ShortestPathInBinaryMatrix/main.cpp)
target_link_libraries(test_shortest_path_in_binary_matrix gtest Threads::Threads)

# Make sure third-party is built before executable
add_dependencies(test_merge_sort googletest merge_sort)
set_target_properties(test_merge_sort PROPERTIES EXCLUDE_FROM_ALL TRUE)

add_dependencies(test_heap_sort googletest merge_sort)
set_target_properties(test_heap_sort PROPERTIES EXCLUDE_FROM_ALL TRUE)
