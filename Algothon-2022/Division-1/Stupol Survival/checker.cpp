#include "bounds.h"
#include "testlib.h"

#define EPS 0.00001

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    double pans = ouf.readDouble(0, MAX_X);
    double jans = ans.readDouble();

    if (abs(pans - jans) <= EPS ||
        ((1 - EPS) * jans <= pans && pans <= (1 + EPS) * jans)) {
        quitf(_ok, "Answer within specified range");
    } else {
        quitf(_wa, "Incorrect answer supplied: expected %.5lf, found %.5lf",
              jans, pans);
    }
}