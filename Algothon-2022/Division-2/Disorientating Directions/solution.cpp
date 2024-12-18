#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

template <class T>
T _abs(T n) {
    return (n < 0 ? -n : n);
}
template <class T>
T _max(T a, T b) {
    return (!(a < b) ? a : b);
}
template <class T>
T _min(T a, T b) {
    return (a < b ? a : b);
}
template <class T>
T sq(T x) {
    return x * x;
}

#define ALL(p) p.begin(), p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair<int, int>
#define psi pair<string, int>
#define vi vector<int>

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
char ln[130];

double dfs(int p, int cr, int tg) {
    if (!ln[p]) return cr == tg;
    if (ln[p] == '+') return dfs(p + 1, cr + 1, tg);
    if (ln[p] == '-') return dfs(p + 1, cr - 1, tg);
    return 0.5 * (dfs(p + 1, cr - 1, tg) + dfs(p + 1, cr + 1, tg));
}

int main() {
    // READ("in.txt");
    // WRITE("out.txt");
    cin >> ln;
    int i, t = 0;
    for (i = 0; ln[i]; i++) {
        if (ln[i] == '+')
            t++;
        else
            t--;
    }
    cin >> ln;
    printf("%.10lf\n", dfs(0, 0, t));
    return 0;
}