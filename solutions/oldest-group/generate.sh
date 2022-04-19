#!/bin/bash

mkdir -p "tests/input"
mkdir -p "tests/output"
i=0
while [ $i -lt 20 ]
do
    echo "$i: Generating input"
    python3 generateTest.py > "tests/input/input$i.txt"
    echo "$i: Finished input"
    echo "$i: Generating output"
    ./solution < "tests/input/input$i.txt" > "tests/output/output$i.txt"
    echo "$i: Finished output"
    i=$(( i + 1 ))
done
