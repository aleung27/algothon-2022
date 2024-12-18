#include <iostream>

#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int r = rnd.wnext(MAX_R + 1, -10);
    int c = rnd.next(MIN_C, MAX_AREA / r);

    cout << r << " " << c << endl;

    vector<vector<char>> grid(r, vector<char>(c));
    vector<pair<int, int>> puddles, drys;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int isPuddle = rnd.next(2);
            grid[i][j] = (isPuddle ? 'X' : '.');
            cout << grid[i][j];

            if (isPuddle)
                puddles.push_back({i, j});
            else
                drys.push_back({i, j});
        }
        cout << endl;
    }

    int puddleRange = puddles.size() - 1;
    bool canClean = true;

    int q = rnd.next(MIN_Q, MAX_Q);
    cout << q << endl;

    for (int i = 0; i < q; i++) {
        if (puddleRange < 0) canClean = false;

        int isD = rnd.next(2);
        if (isD && !canClean) isD = 0;

        cout << (isD ? "d " : "p ");

        if (isD) {
            int idx = rnd.next(0, puddleRange);
            cout << puddles[idx].first << " " << puddles[idx].second << endl;

            puddles.push_back(puddles[idx]);
            swap(puddles[idx], puddles[puddleRange]);
            puddleRange--;
        } else {
            int idx = rnd.next(0, (int)drys.size() - 1);
            int idx2 = rnd.next(0, (int)drys.size() - 1);

            cout << drys[idx].first << " " << drys[idx].second << " "
                 << drys[idx2].first << " " << drys[idx2].second << endl;
        }
    }
}