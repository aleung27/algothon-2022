#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();

    int fires = 0;

    for (int i = 0; i < n; i++) {
        char next = inf.readChar();
        if (next == 'F') fires++;
    }

    ensuref(fires <= n / 2, "Invalid amount of fires present");

    inf.readEoln();
    inf.readEof();
}