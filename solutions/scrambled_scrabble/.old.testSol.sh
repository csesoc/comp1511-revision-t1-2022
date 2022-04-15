#!/bin/bash

i=0

while [ $i -lt 20 ]
do
    inputNo="$i"

    if [[ ${#input} < 2 ]]
    then
        inputNo="0${inputNo}"
        inputNo="${inputNo: -2}"
    fi

    ./scrambled_scrabble < "testBin/input$inputNo.txt" > temp
    diff temp "testBin/output$inputNo.txt"

    error=$?
    if [ $error -eq 0 ]
    then
        echo "Test $inputNo passed!"
    else
        echo "Test $inputNo failed!"
    fi
    i=$(( $i + 1 ))
    rm temp
done
