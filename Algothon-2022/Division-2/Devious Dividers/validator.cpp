#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    long long h = inf.readLong(MIN_H, MAX_H);
    inf.readSpace();
    long long w = inf.readLong(MIN_W, MAX_W);
    inf.readEoln();

    int dw = inf.readInt(MIN_DIVIDERS, min(MAX_DIVIDERS, w - 1));
    for (int i = 0; i < dw; i++) {
        inf.readSpace();
        long long next = inf.readLong(1LL, w - 1);
    }
    inf.readEoln();

    int dh = inf.readInt(MIN_DIVIDERS, min(MAX_DIVIDERS, h - 1));
    for (int i = 0; i < dh; i++) {
        inf.readSpace();
        long long next = inf.readLong(1LL, h - 1);
    }
    inf.readEoln();
    inf.readEof();
}