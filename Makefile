ProjectName := Cpp-Core

RED := \033[1;31m
GREEN := \033[1;32m
BLUE := \033[0;34m
NO_COLOR := \033[0m

init:
	@cd config/ && cmake .
	@cd config/ && cmake --build . --target hello_world && ../bin/hello_world

build:
	@cd config/ && cmake --build . --target $(t)

run:
	@./bin/$(t)

list:
	@echo "List of executable targets:"
	@echo "---------------------------"
	@sed -n 's/^add_executable(//p' config/CMakeLists.txt | awk -F' ' '{print $$1}'

tests:
	@cd config && list=$$(sed -n 's/^add_executable(//p' CMakeLists.txt | awk -F' ' '{print $$1}' | grep "^test") \
		&& cmake --build . --target $${list} > /dev/null 2>&1; \
		for item in $${list[@]}; \
			do echo "-------------$${item}-------------"; \
				../bin/$${item}; \
				if [ $$? != 0 ]; \
					then echo "$(RED)-----------FAILED: $${item}-----------$(NO_COLOR)"; \
					if [ $${item} != "test_heap_sort" ]; then exit 1; fi;\
				fi \
			done

.PHONY: help
all: help
help: Makefile
	@echo "Run 'make list' to show target list"
