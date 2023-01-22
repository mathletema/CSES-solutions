/**
 * Counting Towers
 * url: https://cses.fi/problemset/task/2413
 * date: 1/22/23
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
int t, n;
ll f[1000001];

int main () {
    f[1] = 2; f[2] = 8;

    for (int i = 3; i <= 1000001; i++) {
        f[i] = 6 * f[i-1] - 7 * f[i-2];
        f[i] += 7 * MOD; f[i] %= MOD;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << f[n] << endl;
    }
}