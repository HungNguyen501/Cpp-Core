## fibonacci
fibonacci:
	@clang++ fibonacci.cpp -o fibonacci.o && ./fibonacci.o

## count_paths
count_paths:
	@clang++ count_paths.cpp -o count_paths.o && ./count_paths.o

.PHONY: help
all: help
help: Makefile
	@echo "Choose a project to run"
	@sed -n 's/^##//p' $< | column -t -s ':' |  sed -e 's/^/ /'
