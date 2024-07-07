Cpp-Core
===

![C++](https://img.shields.io/badge/-c++-black?logo=c%2B%2B&style=social)
![Test badge](https://github.com/python/cpython/actions/workflows/build.yml/badge.svg?branch=main&event=push)

Copyright (C) 2024 @github.com:HungNguyen501<br>
All rights reserved.<br>

**Agenda**<br>
[1. Prerequisites](#1-prerequisites)<br>
[2. Cmake Config](#2-cmake-config)<br>

## 1. Prerequisites
- Coding convention: [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- Gcc version:
```bash
$ g++ --version
g++ (Ubuntu 13.2.0-23ubuntu4) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
- Cmake version:
```bash
$ cmake --version
cmake version 3.29.3
CMake suite maintained and supported by Kitware (kitware.com/cmake).
```
- Bazel version:
```bash
$ bazel --version
bazel 7.2.1
```
- Install Cmake components: `$ make install`
<details>
<summary>See output</summary>

```bash
-- Configuring done (0.1s)
-- Generating done (0.1s)
-- Build files have been written to: /home/mrroot501/Projects/Cpp-Core/configurations
gmake[1]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations'
gmake[2]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations'
gmake[3]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations'
gmake[4]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations'
gmake[4]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations'
gmake[4]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations'
[ 10%] Performing update step for 'googletest'
[ 20%] No patch step for 'googletest'
[ 30%] Performing configure step for 'googletest'
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build
[ 40%] Performing build step for 'googletest'
gmake[5]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[6]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
[ 25%] Built target gtest
gmake[7]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
[ 50%] Built target gmock
gmake[7]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
[ 75%] Built target gmock_main
gmake[7]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
[100%] Built target gtest_main
gmake[6]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[5]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
[ 50%] Performing install step for 'googletest'
gmake[5]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[6]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
[ 25%] Built target gtest
gmake[7]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
[ 50%] Built target gmock
gmake[7]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
[ 75%] Built target gmock_main
gmake[7]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
gmake[7]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
[100%] Built target gtest_main
gmake[6]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations/lib/src/googletest-build'
Install the project...
-- Install configuration: ""
-- Up-to-date: /home/mrroot501/Projects/Cpp-Core/configurations/lib/installed/include
[ 60%] Completed 'googletest'
gmake[4]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations'
[ 80%] Built target googletest
gmake[4]: Entering directory '/home/mrroot501/Projects/Cpp-Core/configurations'
gmake[4]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations'
[100%] Built target hello_world
gmake[3]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations'
gmake[2]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations'
gmake[1]: Leaving directory '/home/mrroot501/Projects/Cpp-Core/configurations'
Hello World!
bazel 7.3.1
g++ (Ubuntu 13.2.0-23ubuntu4) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
</details>

## 2. Cmake Config
Config file: `$ configurations/CMakeLists.txt`<br>
List all executable targets in Cmake: `$ make list`<br>
Build target in Cmake: `$ make build t={target}`<br>
Run an executable in cmake: `$ make run t={target}`<br>
