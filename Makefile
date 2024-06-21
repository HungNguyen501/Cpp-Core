ProjectName := Cpp-Core

CiScript := ci/ci.sh

RED := \033[1;31m
GREEN := \033[1;32m
BLUE := \033[0;34m
NO_COLOR := \033[0m

check_ref_name:
	@bash $(CiScript) validate_ref_name $(REF_TYPE) $(REF_NAME)

install:
	@cd configurations/ && cmake .
	@cd configurations/ && cmake --build . --target hello_world && ../bin/hello_world
	@bazel --version
	@g++ --version

clean:
	@cmake --build configurations/ --target clean

build:
	@cd configurations/ && cmake . && cmake --build . --target $(t)

run:
	@cd configurations/ && cmake --build . --target $(t) 1>/dev/null && ../bin/$(t)

list:
	@echo "List of executable targets:"
	@echo "---------------------------"
	@sed -n 's/^add_executable(//p' configurations/CMakeLists.txt | awk -F' ' '{print $$1}'

cmake_test:
	@bash $(CiScript) run_tests

test:
	@bash $(CiScript) run_bazel_tests
	@bazel clean --async

run_ci:
	@bash $(CiScript) run_ci $(CHANGES)
	@bazel clean --async

.DEFAULT_GOAL := help
.PHONY: help
all: help
help: Makefile
	@echo "Hello World!"

