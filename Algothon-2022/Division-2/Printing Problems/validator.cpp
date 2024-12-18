#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        int weight = inf.readInt(MIN_WEIGHT, MAX_WEIGHT);
        inf.readSpace();
        int support = inf.readInt(MIN_SUPPORT, MAX_SUPPORT);
        inf.readEoln();
    }

    inf.readEof();
}