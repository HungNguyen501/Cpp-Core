cmake_minimum_required (VERSION 3.10)

project(CPP-Core) # Set the project name


# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


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
add_library(extra_long_factorial ProblemSolving/ExtraLongFactorial/extra_long_factorial.cpp)
add_library(merge_sort Algorithms/MergeSort/merge_sort.cpp)
add_library(heap_sort Algorithms/HeapSort/heap_sort.cpp)


# Add targets for main program
add_executable(main ProblemSolving/ExtraLongFactorial/main.cpp)
target_link_libraries(main extra_long_factorial)


# Add targets for testing
add_executable(test_extra_long_factorial ProblemSolving/ExtraLongFactorial/test_extra_long_factorial.cpp)
target_link_libraries(test_extra_long_factorial extra_long_factorial gtest Threads::Threads)

add_executable(test_merge_sort Algorithms/MergeSort/test_merge_sort.cpp)
target_link_libraries(test_merge_sort merge_sort gtest Threads::Threads)

add_executable(test_heap_sort Algorithms/HeapSort/test_heap_sort.cpp)
target_link_libraries(test_heap_sort heap_sort gtest Threads::Threads)

# Make sure third-party is built before executable
add_dependencies(test_extra_long_factorial googletest extra_long_factorial)
set_target_properties(test_extra_long_factorial PROPERTIES EXCLUDE_FROM_ALL TRUE)

add_dependencies(test_merge_sort googletest merge_sort)
set_target_properties(test_merge_sort PROPERTIES EXCLUDE_FROM_ALL TRUE)

add_dependencies(test_heap_sort googletest merge_sort)
set_target_properties(test_heap_sort PROPERTIES EXCLUDE_FROM_ALL TRUE)
