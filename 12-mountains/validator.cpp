#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MIN_N  = 1;
const int MAX_N  = 100000;
const int MIN_HEIGHT  = 1;
const int MAX_HEIGHT  = 1000000;
const int MIN_R = -1;
const int MAX_R = 1;


class Checker {
public:

    Checker() {};

    set<string> words;

    void validate() {
        registerValidation();

        int n = inf.readInt(MIN_N, MAX_N, "N");
        inf.readEoln();

        #ifdef SUB1
            ensuref(n <= 20, "sub1 n <= 20");
        #endif
        #ifdef SUB2
            ensuref(n <= 1000, "sub2 n <= 1000");
        #endif

        for (int i = 0; i < n; i++) {
            int h = inf.readInt(MIN_HEIGHT, MAX_HEIGHT, "H[i]");
            if (i+1 == n) {
                inf.readEoln();
            } else {
                inf.readSpace();
            }
        }

        for (int i = 0; i < n; i++) {
            int r = inf.readInt(MIN_R, MAX_R, "R[i]");

            #ifdef SUB3
                ensuref(r >= 0, "sub3 r[i] >= 0");
            #endif
            
            if (i+1 == n) {
                inf.readEoln();
            } else {
                inf.readSpace();
            }
        }

        inf.readEof();
    }
};

int main() {
    Checker c;
    c.validate();
}
