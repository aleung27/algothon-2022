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
    ll h, w;
    cin >> h >> w;

    ll dw, dh;
    cin >> dw;

    vector<ll> dividersW(dw);
    for (int i = 0; i < dw; i++) {
        cin >> dividersW[i];
    }

    cin >> dh;
    vector<ll> dividersH(dh);
    for (int i = 0; i < dh; i++) {
        cin >> dividersH[i];
    }

    dividersW.push_back(w);
    dividersH.push_back(h);
    sort(dividersW.begin(), dividersW.end());
    sort(dividersH.begin(), dividersH.end());

    vector<ll> distW, distH;

    distW.push_back(dividersW[0]);
    distH.push_back(dividersH[0]);

    for (int i = 1; i < dividersW.size(); i++) {
        distW.push_back(dividersW[i] - dividersW[i - 1]);
    }
    for (int i = 1; i < dividersH.size(); i++) {
        distH.push_back(dividersH[i] - dividersH[i - 1]);
    }

    sort(distW.begin(), distW.end(), std::greater<int>());
    sort(distH.begin(), distH.end(), std::greater<int>());

    double keepW = distW[0] * max((double)distH[0] / 2.0, (double)distH[1]);
    double keepH = distH[0] * max((double)distW[0] / 2.0, (double)distW[1]);

    cout << fixed << setprecision(1) << min(keepH, keepW) << endl;

    return 0;
}
