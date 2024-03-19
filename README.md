License
---

Copyright (C) 2024 @HungNguyen501<br>
All rights reserved.

Development Guide
---

# How to run a CPP file
```bash
g++ main.cpp -o main.o && ./main.o
```

# Makefile
- Go to one of following modules:
```bash
.
├── Algorithms
├── DataStructure
├── DynamicProgramming
└── ProblemSolving
```
- Command helps:
```bash
make help # Helper
make clean # Clean CPP output files and dependencies
make validateTargets # Verify all targets is added to Makefile 
make -B ${module_name} # Run a target coresponding to sub-module name
```

