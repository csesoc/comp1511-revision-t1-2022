#!/bin/bash

mkdir -p "tests/input"
mkdir -p "tests/output"
i=0
while [ $i -lt 20 ]
do
    echo "$i: Generating input"
    python3 generate.py > "tests/input/input$i.txt"
    echo "$i: Done input"
    echo "$i: Generating output"
    ./solution < "tests/input/input$i.txt" > "tests/output/output$i.txt"
    ./fastsol < "tests/input/input$i.txt" > "temp"
    diff temp "tests/output/output$i.txt"
    err=$?
    if [[ $err == 1 ]]
    then
        echo "Difference between fastsol and solution"
        exit 1
    fi
    echo "$i: Done output"
    i=$(( $i + 1 ))

done
