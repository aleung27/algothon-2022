#include <iomanip>
#include <iostream>

#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int x = rnd.next(MIN_X, MAX_X);
    int y = rnd.next(MIN_Y, MAX_Y);
    int n = rnd.next(MIN_N, MAX_N);

    cout << x << " " << y << endl;
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        double xi = rnd.next((double)MIN_X, (double)x);
        double yi = rnd.next((double)MIN_Y, (double)y);
        cout << fixed << setprecision(5) << xi << " " << yi << endl;
    }

    return 0;
}