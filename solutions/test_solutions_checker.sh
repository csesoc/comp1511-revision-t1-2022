#!/bin/bash

# checks that all solution*.* get AC when checked by checker.py (in hackerrank format)
# run this script from the problem directory

if [ ! -e checker.py ]; then
    echo "no checker.py file"
    exit 1
fi

echo "Testing judge solutions"

for sol in solution*; do
    echo "-------------------"
    echo "Testing $sol"
    echo "-------------------"
    
    if [ "${sol#*.}" == "c" ]; then
        gcc $sol -O2
    elif [ "${sol#*.}" == "cpp" ]; then
        g++ $sol -std=c++14 -O2
    fi
    
    for input in ./tests/input/*; do
        echo "$input"
        output=${input//in/out}

        if [ -e $output ]; then
            
            echo -n "Test $input "
            
            if [ "${sol#*.}" == "py" ]; then
                python3 $sol < $input > temp
            elif [ "${sol#*.}" == "c" ]; then
                ./a.out < $input > temp
            elif [ "${sol#*.}" == "cpp" ]; then
                ./a.out < $input > temp
            else
                echo "file extension not supported. bad"
            fi
            
            echo '{"testcase_id" : 0,"input_file_path" : '"\"$input\""',"output_file_path" : "temp","expected_output_file_path" : '"\"$output\""',"error_file_path" : "","metadata_file_paths" : [],"submission_code_path" : "","submission_language" : "","testcase_result" : false,"testcase_signal" : 0,"testcase_time" : 0,"testcase_memory" : 0.0,"data" : ""}' > input_json.json
            
            python3 checker.py input_json.json
            
        else
            echo "$output does not exist. the generator is supposed to do this"
        fi
    done
done

if [ -e input_json.json ]; then
    rm input_json.json
fi
if [ -e a.out ]; then
    rm a.out
fi
if [ -e temp ]; then
    rm temp
fi
