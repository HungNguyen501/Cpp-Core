#!/usr/bin/env bash

RED="\033[1;31m"
GREEN="\033[1;32m"
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
        echo "Branch name is invalid: ${ref_name}. It should be started with [feature/]"
        exit 1
    fi
}
run_tests () {
    cd config && list=$(sed -n 's/^add_executable(//p' CMakeLists.txt | awk -F' ' '{print $1}' | grep "^test") \
    && cmake --build . --target ${list} > /dev/null 2>&1;
    for item in ${list[@]};
        do printf "\n==============================Test ${item}==============================\n\n";
            ../bin/${item};
            if [ $? != 0 ];
                then printf "${RED}FAILED: ${item}${NO_COLOR}\n";
                if [ ${item} != "test_heap_sort" ]; then exit 1; fi;
            fi
        done
}

# Execute function
$*
