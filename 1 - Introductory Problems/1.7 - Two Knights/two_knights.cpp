/**
 * Two Knights
 * url: https://cses.fi/problemset/task/1072
 * date: 1/20/2023
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int N;

ll f(ll k) {return (ll) (k-4) * (k - 4) * 8 + 4 * (k - 4) * 6 + 4 * 4 + 4 * (k-4) * 4 + 8 * 3 + 4 * 2;}

ll g(ll k) {
    if (k == 1) return 0;
    if (k == 1) return 6;
    if (k == 1) return 28;
    if (k == 1) return 96;
    ll l = k * k * (k * k -1); l = l / 2;
    return l - f(k) / 2;
}

int main () {
    cin >> N;
    for (int i = 1; i <= N; i++) cout << g(i) << "\n";
}