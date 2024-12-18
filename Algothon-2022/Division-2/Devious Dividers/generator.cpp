#include <iostream>

#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    long long h = rnd.next(MIN_H, MAX_H);
    long long w = rnd.next(MIN_W, MAX_W);

    int dw = rnd.next(MIN_DIVIDERS, min(MAX_DIVIDERS, w - 1));
    int dh = rnd.next(MIN_DIVIDERS, min(MAX_DIVIDERS, h - 1));

    cout << h << " " << w << endl;

    cout << dw;
    set<long long> dividersW;
    vector<long long> unsortedW;
    while (dw > 0) {
        long long next = rnd.next(1LL, w - 1);
        if (dividersW.insert(next).second) {
            dw--;
            unsortedW.push_back(next);
        }
    }

    for (auto it = unsortedW.begin(); it != unsortedW.end(); it++) {
        cout << " " << *it;
    }

    cout << endl;

    cout << dh;
    set<long long> dividersH;
    vector<long long> unsortedH;
    while (dh > 0) {
        long long next = rnd.next(1LL, h - 1);
        if (dividersH.insert(next).second) {
            dh--;
            unsortedH.push_back(next);
        }
    }
    for (auto it = unsortedH.begin(); it != unsortedH.end(); it++) {
        cout << " " << *it;
    }

    cout << endl;
}