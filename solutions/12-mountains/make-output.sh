for i in {0..9}
do
	python3 solution.py < tests/input/input0$i.txt > tests/output/output0$i.txt
done
for i in {10..26}
do
	python3 solution.py < tests/input/input$i.txt > tests/output/output$i.txt
done