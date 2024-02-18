ProjectName := DataStructure
CC := clang++
CFLAGS := -std=c++11

define run_module
	@echo "Running" $@ "..."
	@$(CC) $(CFLAGS) $@/main.cpp -o $@/main.o && ./$@/main.o
endef

BinaryTree:
	@$(call run_module)

LinkedList:
	@$(call run_module)

Stack:
	@$(call run_module)

clean:
	@-find ./ -type f -name "*.o"  -exec rm -rf {} +

.PHONY: help
all: help
help: Makefile
	@echo "Choose a module to run in project $(ProjectName), syntax: make -B {module}"
	@ls -d */ | awk '{print "- ", $$1}'
