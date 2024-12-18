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

int x, y, n;
vector<pair<double, double>> pts;

double dist(pair<double, double>& a, pair<double, double>& b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second));
}

void dfs(int at, vector<bool>& seen, vector<int> adj[]) {
    seen[at] = true;

    for (const auto& next : adj[at]) {
        if (!seen[next]) {
            seen[next] = true;
            dfs(next, seen, adj);
        }
    }
}

bool test(double r) {
    vector<int> adj[n + 4];
    // n -> left
    // n + 1 -> right
    // n + 2 -> bottom
    // n + 3 -> top

    // Fill in adjlist
    for (int i = 0; i < pts.size(); i++) {
        for (int j = i + 1; j < pts.size(); j++) {
            if (dist(pts[i], pts[j]) <= 2 * r) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }

        if (pts[i].first - r <= 0) {
            adj[i].push_back(n);
            adj[n].push_back(i);
        }
        if (pts[i].first + r >= x) {
            adj[i].push_back(n + 1);
            adj[n + 1].push_back(i);
        }
        if (pts[i].second - r <= 0) {
            adj[i].push_back(n + 2);
            adj[n + 2].push_back(i);
        }
        if (pts[i].second + r >= y) {
            adj[i].push_back(n + 3);
            adj[n + 3].push_back(i);
        }
    }

    // see if l-b, t-r, t-b, l-r
    vector<bool> seen(n + 4, false);
    dfs(n, seen, adj);
    if (seen[n + 2] || seen[n + 1]) return false;

    dfs(n + 3, seen, adj);
    if (seen[n + 2] || seen[n + 1]) return false;

    return true;
}

int main() {
    FASTIO
    cin >> x >> y >> n;

    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        pts.push_back({a, b});
    }

    double l = 0, r = max(x, y);
    while (l <= r && abs(l - r) > 0.00001 * r) {
        double mid = (l + r) / 2;
        // cout << "mid: " << mid << endl;
        if (test(mid)) {
            // cout << "ok" << endl;
            l = mid;
        } else {
            // cout << "fail" << endl;
            r = mid;
        }
    }

    cout << r << endl;

    return 0;
}
