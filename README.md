Cpp-Core
===

![C++](https://img.shields.io/badge/-c++-black?logo=c%2B%2B&style=social)
![Test badge](https://github.com/python/cpython/actions/workflows/build.yml/badge.svg?branch=main&event=push)

Copyright (C) 2024 @github.com:HungNguyen501<br>
All rights reserved.<br>

**Agenda**<br>
[1. Prerequisites](#1-prerequisites)<br>
&emsp;[⦿ Coding convention](#coding-convention)<br>
&emsp;[⦿ Gcc]( #gcc)<br>
&emsp;[⦿ Cmake](#cmake)<br>
&emsp;[⦿ Bazel](#bazel)<br>
[2. Run C++ module](#2-run-c-module)<br>

# 1. Prerequisites
## Coding convention
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

## Gcc
```bash
$ g++ --version
g++ (Ubuntu 13.2.0-23ubuntu4) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## Cmake
```bash
$ cmake --version
cmake version 3.29.3
CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

## Bazel
```bash
$ bazel --version
bazel 7.2.1
```

# 2. Run C++ module
Install Cmake components:
```bash
$ make install
```
List all executable targets in Cmake:
```bash
$ make list
```
Build target in Cmake:
```bash
$ make build t={target}
```
Run an executable in cmake:
```bash
$ make run t={target}
```
