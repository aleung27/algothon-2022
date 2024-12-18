#include <iostream>

#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int length = rnd.next(MIN_S, MAX_S);

    string s1 = "";
    string s2 = "";
    for (int i = 0; i < length; i++) {
        int chance = rnd.next(2);
        s1 += (chance ? "+" : "-");
    }

    for (int i = 0; i < length; i++) {
        int chance = rnd.wnext(2, -2);
        s2 += (chance ? "?" : string(1, s1[i]));
    }

    cout << s1 << endl;
    cout << s2 << endl;
}