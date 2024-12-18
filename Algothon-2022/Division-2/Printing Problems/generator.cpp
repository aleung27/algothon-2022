#include <iostream>

#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(MIN_N, MAX_N);

    cout << n << endl;

    for (int i = 0; i < n; i++) {
        int weight = rnd.next(MIN_WEIGHT, MAX_WEIGHT);
        int support = rnd.next(MIN_SUPPORT, MAX_SUPPORT);
        cout << weight << " " << support << endl;
    }
}