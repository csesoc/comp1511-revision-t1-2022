g++ -std=c++11 -O2 -o random random.cpp


# Have both sample cases worth 5% (10% total)


# Have 2 impossible cases (each worth 5%)
echo "6\n40 -1 20 -1 10 -1\n" > tests/input/input05.txt
echo "8\n12 -1 -1 -1 -1 -1 -1 1\n" > tests/input/input08.txt

# Have 8 other cases (each worth 10%)
./random 2 1 > tests/input/input02.txt
./random 10 2 > tests/input/input03.txt
./random 10 3 > tests/input/input04.txt
./random 15 4 > tests/input/input06.txt
./random 15 10 > tests/input/input07.txt
./random 40 10 > tests/input/input09.txt
./random 22 22 > tests/input/input10.txt
./random 70 40 > tests/input/input11.txt


rm random