#!/usr/bin/env bash

RED="\033[0;31m"
GREEN="\033[0;32m"
BLUE="\033[0;34m"
NO_COLOR="\033[0m"

validate_ref_name () {
    ref_type=${1}
    ref_name=${2}
    if [ "${ref_type}" == "tag" ] ||
        { 
            [ "${ref_type}" == "branch" ] && 
            [[ "${ref_name}" == "main"  || ${ref_name} == feature/* ]]
        };
    then
        echo "Branch name is qualified: ${ref_name}"
        exit 0
    else
        echo "Branch name is denied: ${ref_name}. It should be started with [feature/]"
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
                if [ ${item} != "test_heap_sort" ] && [ ${item} != "test_stack" ] ; then exit 1; fi;
            fi
        done
}
run_bazel_tests () {
    tests=$(bazel query --keep_going --noshow_progress   "kind(test, ... - //configurations/lib/...)")
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
    files=()
    IFS=',' read -r -a changed_files <<< "${1}"
    for file_name in ${changed_files[@]}; do
        files+=("$(bazel query --keep_going --noshow_progress "${file_name}") ")
    done
    tests=$(bazel query --keep_going --noshow_progress   "kind(test, rdeps(//..., set(${files[*]})))")
    if [[ ! -z ${tests} ]];
    then
        printf "${GREEN}Running tests...\n"; \
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

# Execute function
$*
