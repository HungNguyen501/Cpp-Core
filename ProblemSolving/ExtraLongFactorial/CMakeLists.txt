cmake_minimum_required (VERSION 3.10)

# Define the project
project(CPP-Core)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Add definition for library
add_library(extra_long_factorial extra_long_factorial.cpp)


# Third-party library
include(ExternalProject)
ExternalProject_Add(googletest
    PREFIX "${CMAKE_BINARY_DIR}/lib"
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "main"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/lib/installed
)


# Prevent build on all targets build
set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)


# Define ${CMAKE_INSTALL_...} variables
include(GNUInstallDirs)


# Specify where third-party libraries are located
link_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_INCLUDEDIR})


# This is required for googletest
find_package(Threads REQUIRED)

# Add definition for the cmake-tutorial binary
# add_executable(main main.cpp)
# target_link_libraries(main extra_long_factorial)

# Test
add_executable(test_extra_long_factorial test_extra_long_factorial.cpp)
target_link_libraries(test_extra_long_factorial extra_long_factorial gtest Threads::Threads)


# Make sure third-party is built before executable
add_dependencies(test_extra_long_factorial googletest)
set_target_properties(test_extra_long_factorial PROPERTIES EXCLUDE_FROM_ALL TRUE)
