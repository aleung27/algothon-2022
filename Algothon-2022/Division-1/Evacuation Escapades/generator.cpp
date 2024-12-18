#include <iostream>

#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(MIN_N, MAX_N);

    cout << n << endl;

    string s = "";
    int firesLeft = n / 2;

    for (int i = 0; i < n; i++) {
        if (firesLeft) {
            int isFire = rnd.next(0, 1);
            if (isFire) {
                s += "F";
                firesLeft--;
            } else {
                s += "S";
            }
        } else {
            s += "S";
        }
    }

    cout << s << endl;

    return 0;
}