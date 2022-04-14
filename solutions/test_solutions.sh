#!/bin/bash

# checks that all solution*.* have the same output
# run this script from the problem directory

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
            
            diff -b temp $output > /dev/null
            if [ $? -eq 0 ]; then
                echo "correct"
            else
                echo "incorrect"
                #diff -b temp $output
            fi
            
        else
            echo "$output does not exist. the generator is supposed to do this"
        fi
    done
done

if [ -e a.out ]; then
    rm a.out
fi
if [ -e temp ]; then
    rm temp
fi
