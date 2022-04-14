# N <= 1000, all 0s and 1s
./gen 1000 10 0 10 0 0.2 > tests/input/input09.txt
./gen 1000 100 20 10 0 0.3 > tests/input/input10.txt
./gen 1000 5 100 30 0 0.16 > tests/input/input11.txt

# N <= 1000
./gen 1000 10 10 5 10 0.5 > tests/input/input12.txt
./gen 1000 100 50 1 3 0.59 > tests/input/input13.txt
./gen 1000 3 100 1 8 0.2 > tests/input/input14.txt

# N <= 100000 and all 0s and 1s
./gen 100000 10000 1000 20 0 0.5 > tests/input/input15.txt
./gen 100000 1000 1000 10 0 0.6 > tests/input/input16.txt
./gen 100000 500 2000 1000 0 0.2 > tests/input/input17.txt
./gen 100000 200 5000 200 0 0.2 > tests/input/input18.txt
./gen 100000 100 1000 800 0 0.2 > tests/input/input19.txt
./gen 100000 10 1000 5000 0 0.2 > tests/input/input20.txt

# N <= 100000
./gen 100000 10000 1000 20 40 0.5 > tests/input/input21.txt
./gen 100000 1000 1000 10 21 0.6 > tests/input/input22.txt
./gen 100000 500 2000 200 1100 0.2 > tests/input/input23.txt
./gen 100000 200 5000 40 400 0.2 > tests/input/input24.txt
./gen 100000 100 1000 1 1 0.51 > tests/input/input25.txt
./gen 100000 10 1000 1000 6000 0.2 > tests/input/input26.txt