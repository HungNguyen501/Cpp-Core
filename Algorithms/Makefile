ProjectName := Algorithms
CC := clang++
CFLAGS := -std=c++11

define run_module
	@echo "Running" $@ "..."
	@$(CC) $(CFLAGS) $@/main.cpp -o $@/main.o && ./$@/main.o
endef

##BFS
BFS:
	@$(call run_module)

##QuickSort
QuickSort:
	@$(call run_module)

##BoyerMoore
BoyerMoore:
	@$(call run_module)

##BinarySearch
BinarySearch:
	@$(call run_module)

##Dijkstra
Dijkstra:
	@$(call run_module)

##MergeSort
MergeSort:
	@$(call run_module)

##MergeSortExternal
MergeSortExternal:
	@$(call run_module)

##KruskalMST
KruskalMST:
	@$(call run_module)

clean:
	@-rm -f */*.o

.PHONY: help
all: help
help: Makefile
	@echo "Choose a module to run in project $(ProjectName)"
	@echo "Syntax: make -B {module}"
	@sed -n 's/^##//p' $< | column -t -s ':' |  sed -e 's/^/ /'
