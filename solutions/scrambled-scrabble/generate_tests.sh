#!/bin/bash

i=10
mkdir -p "testBin/"

while [ $i -lt 20 ]
do
    python3 generate_case.py > "testBin/input$i.txt"
    cat "testBin/input$i.txt" | ./scrambled_scrabble > "testBin/output$i.txt"
    i=$(( $i + 1 ))
done

