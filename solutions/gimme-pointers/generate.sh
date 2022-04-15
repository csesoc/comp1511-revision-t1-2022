generate_output() {
    for entry in "tests/input"/*
    do
        if [[ $entry =~ ^(.*)([0-9]{2}\.txt)$ ]]
        then
            base=${BASH_REMATCH[2]}
            ./solution < $entry > "tests/output/output$base"
        fi
    done
}

shuffle_up() {
    entries=$( ls tests/input/* | tac )
    
    for entry in $entries
    do
        if [[ $entry =~ ^.*([0-9]{2})\.txt$ ]]
        then
            base=${BASH_REMATCH[1]}

            if [[ $((10#$base >= $1)) == 1 ]]
            then
                increment=$(printf "%02d" $((10#$base + 1)))
                mv "tests/input/input$base.txt" "tests/input/input$increment.txt"
            fi
        fi
    done
}

case "$1" in
    "-o"|"--output")  generate_output  ;;
    "-s"|"--shuffle") shuffle_cases $2 ;;
esac
