#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int x = inf.readInt(MIN_X, MAX_X);
    inf.readSpace();
    int y = inf.readInt(MIN_Y, MAX_Y);
    inf.readEoln();

    int n = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        double xi = inf.readDouble(MIN_X, x);
        inf.readSpace();
        double yi = inf.readDouble(MIN_Y, y);
        inf.readEoln();
    }

    inf.readEof();
}