License
---
Copyright (C) 2024 @github.com/HungNguyen501<br>
All rights reserved.

Development Guide
---

Agenda

[1. Prerequisites](#1-prerequisites)
* [Coding convention](#coding-convention)
* [Gcc]( #gcc)
* [Cmake](#cmake)

[2. Run C++ files](#2-run-c-module)

# 1. Prerequisites
## Coding convention
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

## Gcc
```bash
$ clang++ --version
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: arm64-apple-darwin23.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

$ clang++ -std=c++17 binary_tree.cpp main.cpp -o main.o && ./main.o
```
## Cmake
```bash
$ cmake --version
cmake version 3.29.3
CMake suite maintained and supported by Kitware (kitware.com/cmake).
```


# 2. Run C++ module
Initial Cmake components:

```bash
$ cmake .
$ cmake --build . --target test_merge_sort && ./bin/test_merge_sort  # Install required libraries
```

Run test in Cmake:
```bash
$ cmake .
$ cmake --build . --target {test_target} && ./bin/{test_target}
```

Run executabl in cmake:

```bash
$ cmake --build . --target {executable} && ./bin/{executable}
```
