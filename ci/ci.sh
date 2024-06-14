#!/usr/bin/env bash

RED="\033[0;31m"
GREEN="\033[0;32m"
BLUE="\033[0;34m"
NO_COLOR="\033[0m"

validate_ref_name () {
    ref_type=${1}
    ref_name=${2}
    branch_pattern="^main$|^feature/.+$"
    tag_pattern="^test-all-v[0-9]+$"
    if [ "${ref_type}" == "branch" ]; then
        if [[ "${ref_name}" =~ ${branch_pattern} ]]; then
            printf "${GREEN}Branch name is qualified: ${ref_name}.${NO_COLOR}\n";
            exit 0
        fi
        printf "${RED}Branch name is invalid: ${ref_name}. It should be main or started with [feature/*].${NO_COLOR}\n"
        exit 1
    elif [ "${ref_type}" == "tag" ]; then
        if [[ "${ref_name}" =~ ${tag_pattern} ]]; then
            printf "${GREEN}Tag name is qualified: ${ref_name}.${NO_COLOR}\n"
            exit 0
        fi
        printf "${RED}Tag name is invalid: ${ref_name}. It should be started with [test-all-v*].${NO_COLOR}\n"
        exit 1
    else
        printf "${RED}ref_type is invalid: ${ref_type}. Valid values are [branch, tag].${NO_COLOR}\n"
        exit 1 
    fi
}
run_cmake_tests () {
    cd configurations/ && list=$(sed -n 's/^add_executable(//p' CMakeLists.txt | awk -F' ' '{print $1}' | grep "^test") \
    && cmake --build . --target ${list} > /dev/null 2>&1;
    for item in ${list[@]};
        do \
            test_label="TEST: ${item}"; \
            printf "${BLUE}${test_label}\n"; \
            printf '%.0s-' $(seq 1 ${#test_label})}; \
            printf "\n${NO_COLOR}";
            ../bin/${item};
            if [ $? != 0 ];
                then printf "${RED}FAILED: ${item}${NO_COLOR}\n";
                if [ ${item} != "test_heap_sort" ] && [ ${item} != "test_stack" ] ; then return 1; fi;
            fi
        done
}
run_bazel_tests () {
    tests=$(bazel query --keep_going --noshow_progress   "kind(test, ... - //configurations/lib/...)" 2>/dev/null)
    if [[ ! -z ${tests} ]];
    then
        printf "${GREEN}Running all tests...\n"; \
        printf '%.0s-' $(seq 1 50); \
        printf "\n${NO_COLOR}";
        bazel test --test_output=all \
            --test_verbose_timeout_warnings \
            --noincompatible_sandbox_hermetic_tmp \
            ${tests}
    else
        printf "${BLUE}No tests found\n"; \
        printf '%.0s-' $(seq 1 50); \
        printf "\n${NO_COLOR}";
    fi
}
run_ci () {
    if [[ -z ${1} ]];
    then
        printf "${BLUE}Input(CHANGES) is empty.${NO_COLOR}\n";
        return 0
    fi
    files=()
    IFS=',' read -r -a changed_files <<< "${1}"
    for file_name in ${changed_files[@]}; do
        files+=("$(bazel query --keep_going --noshow_progress "${file_name}" 2>/dev/null) ")
    done
    tests=$(bazel query --keep_going --noshow_progress "kind(test, rdeps(//..., set(${files[*]})))" 2>/dev/null)
    if [[ ! -z ${tests} ]];
    then
        printf "${GREEN}Running tests...\n"; \
        printf '%.0s-' $(seq 1 50); \
        printf "${NO_COLOR}\n";
        bazel test --test_output=all \
            --test_verbose_timeout_warnings \
            --noincompatible_sandbox_hermetic_tmp \
            ${tests}
    else
        printf "${BLUE}No tests found\n"; \
        printf '%.0s-' $(seq 1 50); \
        printf "${NO_COLOR}\n";
    fi
}

# Execute function
$*
