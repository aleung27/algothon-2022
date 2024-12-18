#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define mset(a, b) memset(a, b, sizeof a)
#define pb push_back
#define mp make_pair
typedef vector<ll> vll;
string s1, s2;
int fim, events, equals;
void solve(int ind, int v) {
    if (ind == s2.length()) {
        events++;
        equals += v == fim;
    } else {
        if (s2[ind] == '?') {
            solve(ind + 1, v - 1);
            solve(ind + 1, v + 1);
        } else {
            if (s2[ind] == '+')
                solve(ind + 1, v + 1);
            else
                solve(ind + 1, v - 1);
        }
    }
}
int main() {
    cout << fixed << setprecision(12);
    fim = 0;
    cin >> s1 >> s2;
    for (auto &t : s1) {
        fim += (t == '+');
        fim -= (t == '-');
    }
    solve(0, 0);
    cout << double(equals) / events << endl;
    return 0;
}