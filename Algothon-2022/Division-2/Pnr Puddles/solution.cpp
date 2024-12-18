#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a) * (b)).Y
#define DOTPROD(a, b) ((a).X * (b).X + (a).Y + (b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <class T>
T lcm(T a, T b) {
    return a * b / gcd<T>(a, b);
}

template <class T>
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

vector<int> link, size;
int r, c;
bool seen[100005] = {false};

int cti(int y, int x) { return y * c + x; };

int find(int x) {
    while (x != link[x]) x = link[x];

    return x;
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

void dfs(vector<vector<bool>>& grid, int y, int x) {
    seen[cti(y, x)] = true;
    if (grid[y][x]) return;

    for (int i = 0; i < 4; i++) {
        if (y + dy[i] < 0 || y + dy[i] >= r || x + dx[i] < 0 ||
            x + dx[i] >= c || seen[cti(y + dy[i], x + dx[i])])
            continue;
        if (grid[y + dy[i]][x + dx[i]]) continue;
        join(cti(y, x), cti(y + dy[i], x + dx[i]));
        dfs(grid, y + dy[i], x + dx[i]);
    }
}

int main() {
    char next;
    cin >> r >> c;

    vector<vector<bool>> grid(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> next;

            if (next == '.') {
                grid[i][j] = false;
            } else if (next == 'X') {
                grid[i][j] = true;
            }

            link.push_back(cti(i, j));
            size.push_back(1);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!seen[cti(i, j)]) {
                dfs(grid, i, j);
            }
        }
    }

    int q, r1, c1, r2, c2;
    cin >> q;
    while (q--) {
        cin >> next;
        if (next == 'd') {
            cin >> r1 >> c1;
            grid[r1][c1] = false;
            for (int i = 0; i < 4; i++) {
                if (r1 + dy[i] < 0 || r1 + dy[i] >= r || c1 + dx[i] < 0 ||
                    c1 + dx[i] >= c || grid[r1 + dy[i]][c1 + dx[i]])
                    continue;

                join(cti(r1, c1), cti(r1 + dy[i], c1 + dx[i]));
            }
        } else if (next == 'p') {
            cin >> r1 >> c1 >> r2 >> c2;
            cout << (find(cti(r1, c1)) == find(cti(r2, c2)) ? "YES" : "NO")
                 << endl;
        }
    }

    return 0;
}
