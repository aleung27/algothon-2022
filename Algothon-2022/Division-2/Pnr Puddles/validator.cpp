#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int r = inf.readInt(MIN_R, MAX_R);
    inf.readSpace();
    int c = inf.readInt(MIN_C, MAX_C);
    inf.readEoln();
    ensuref(r * c <= MAX_AREA, "Area out of bounds");

    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char next = inf.readChar();
            ensuref(next == 'X' || next == '.', "Invalid character in grid");
            grid[i][j] = next;
        }
        inf.readEoln();
    }

    int q = inf.readInt(MIN_Q, MAX_Q);
    inf.readEoln();
    for (int i = 0; i < q; i++) {
        char next = inf.readChar();
        ensuref(next == 'd' || next == 'p', "Invalid query character");
        inf.readSpace();

        if (next == 'd') {
            int r1 = inf.readInt(MIN_R - 1, r);
            inf.readSpace();
            int c1 = inf.readInt(MIN_C - 1, c);

            ensuref(grid[r1][c1] == 'X',
                    "Tried to clean a point that is already dry!");
            grid[r1][c1] = '.';
        } else if (next == 'p') {
            int r1 = inf.readInt(MIN_R - 1, r);
            inf.readSpace();
            int c1 = inf.readInt(MIN_C - 1, c);
            inf.readSpace();

            int r2 = inf.readInt(MIN_R - 1, r);
            inf.readSpace();
            int c2 = inf.readInt(MIN_C - 1, c);

            ensuref(grid[r1][c1] == '.', "Path query given wet start point");
            ensuref(grid[r2][c2] == '.', "Path query given wet end point");
        }
        inf.readEoln();
    }

    inf.readEof();
}