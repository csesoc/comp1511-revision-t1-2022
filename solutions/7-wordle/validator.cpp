#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MIN_N  = 1;
const int MAX_N  = 1000;
const int MIN_K  = 1;
const int MAX_K  = 5;


class Checker {
public:

    Checker() {};

    set<string> words;

    void validate() {
        registerValidation();

        int n = inf.readInt(MIN_N, MAX_N, "N");
        inf.readEoln();

        for (int i = 0; i < n; i++) {
            string s = inf.readString("[A-Z]*");
            ensuref(s.size() == 5, "string not of length 5");
            ensuref(words.find(s) == words.end(), "word is not unique");
            words.insert(s);
        }

        int k = inf.readInt(MIN_K, MAX_K, "K");
        inf.readEoln();

        for (int i = 0; i < k; i++) {
            string s = inf.readString("[A-Z]*");
            ensuref(s.size() == 5, "string not of length 5");
            ensuref(words.find(s) != words.end(), "guess does not appear in input");

            s = inf.readString("[GY.]*");
            ensuref(s.size() == 5, "string not of length 5");
        }

        inf.readEof();
    }
};

int main() {
    Checker c;
    c.validate();
}
