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

int main() {
    FASTIO
    int n;
    string s;
    cin >> n;
    cin >> s;

    // people -> place people sitting at
    // empty -> place empty seats are at
    vector<int> people, empty, counts, seats;

    for (int i = 0; i < s.length(); i++) {
        int next = (s[i] == 'F');

        seats.push_back(next);
        next ? people.push_back(i) : empty.push_back(i);

        if (!i)
            counts.push_back(next);
        else
            counts.push_back(counts[counts.size() - 1] + (next ? 1 : 0));
    }

    if (!people.size()) {
        cout << 0 << endl;
        return 0;
    }

    int table[n][n];
    int best_vals[n][n];

    for (int i = 0; i < people.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (seats[j] || i + counts[j] > j) {
                table[i][j] = INT_MAX;
            } else if (!i) {
                table[i][j] = abs(people[i] - j);
            } else {
                table[i][j] = best_vals[i - 1][j - 1] + abs(people[i] - j);
            }
            best_vals[i][j] =
                min(j ? best_vals[i][j - 1] : INT_MAX, table[i][j]);
        }
    }

    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (table[people.size() - 1][i] < min)
            min = table[people.size() - 1][i];
    }

    cout << min << endl;

    return 0;
}
