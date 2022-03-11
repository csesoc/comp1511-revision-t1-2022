#!/bin/bash

g++ -std=c++11 -o sub1 validator.cpp -DSUB1
g++ -std=c++11 -o sub2 validator.cpp -DSUB2
g++ -std=c++11 -o sub3 validator.cpp -DSUB3
g++ -std=c++11 -o full validator.cpp

# TODO: Don't hardcode this
validators=(sub1 sub2 sub3 full)

for val in ${validators[@]}; do
    echo "----------------"
    echo "Validating $val"
    echo "----------------"
    for input in tests/input/*.txt; do
        echo -n "Check $input "
        ./$val < $input
        if [[ $? -eq 0 ]]; then
            echo ""
        fi
    done
done

rm sub?
rm full
