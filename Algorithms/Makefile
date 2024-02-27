ProjectName := Algorithms
CC := clang++
CFLAGS := -std=c++11

define run_module
	@echo "Running" $@ "..."
	@$(CC) $(CFLAGS) $@/main.cpp -o $@/main.o && ./$@/main.o
endef

BFS:
	@$(call run_module)

DFS:
	@$(call run_module)

QuickSort:
	@$(call run_module)

BoyerMoore:
	@$(call run_module)

BinarySearch:
	@$(call run_module)

Dijkstra:
	@$(call run_module)

MergeSort:
	@$(call run_module)

MergeSortExternal:
	@$(call run_module)

KruskalMST:
	@$(call run_module)

HeapSort:
	@$(call run_module)

clean:
	@-find ./ -type f -name "*.o"  -exec rm -rf {} +
	@-find ./ -type d -name "main.dSYM"  -exec rm -rf {} +
	@-find ./ -type d -name "main.o.dSYM"  -exec rm -rf {} +

.PHONY: help
all: help
help: Makefile
	@echo "Choose a module to run in project $(ProjectName), syntax: make -B {module}"
	@ls -d */ | awk '{print "- ", $$1}'
