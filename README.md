License
---
Copyright (C) 2024 @github.com/HungNguyen501<br>
All rights reserved.

Development Guide
---

# Prerequisites
**Installations**<br>
```bash
$ clang++ --version
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: arm64-apple-darwin23.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

$ clang++ -std=c++17 binary_tree.cpp main.cpp -o main.o && ./main.o
```

**Coding convention**<br>
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

# Makefile
```bash
$ make help
Go to one of following modules and then type make help for helper: 
.
├── Algorithms
├── DataStructure
├── DynamicProgramming
└── ProblemSolving

$ make clean # Clean CPP output files and dependencies
$ make validateTargets # Verify all targets added to Makefile 
$ make -B ${module_name} # Run a target coresponding to sub-module name
```
