ProjectName := Cpp-Core

CiScript := ci/ci.sh
GithookScript := ci/githooks.sh

RED := \033[1;31m
GREEN := \033[1;32m
BLUE := \033[0;34m
NO_COLOR := \033[0m

install:
	@cd configurations/ && cmake .
	@cd configurations/ && cmake --build . --target hello_world && ../bin/hello_world
	@bazel --version
	@g++ --version

githook:
	@bash ./$(GithookScript) create_pre_commit_file

check_ref_name:
	@bash $(CiScript) validate_ref_name $(REF_TYPE) $(REF_NAME)

cmake_clean:
	@cmake --build configurations/ --target clean

cmake_build:
	@cd configurations/ && cmake . && cmake --build . --target $(t)

cmake_run:
	@cd configurations/ && cmake --build . --target $(t) 1>/dev/null && ../bin/$(t)

cmake_test:
	@bash $(CiScript) run_cmake_tests

list:
	@echo "List of executable targets:"
	@echo "---------------------------"
	@sed -n 's/^add_executable(//p' configurations/CMakeLists.txt | awk -F' ' '{print $$1}'

test:
	@bash $(CiScript) run_bazel_tests
	@bazel clean --async

verify_changes:
	@bash $(CiScript) verify_changes $(CHANGES)
	@bazel clean --async

.DEFAULT_GOAL := help
.PHONY: help
all: help
help: Makefile
	@echo "Hello World!"

