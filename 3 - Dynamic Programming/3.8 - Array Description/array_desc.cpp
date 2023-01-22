/**
 * Array Description
 * url: https://cses.fi/problemset/task/1746
 * date: 1/20/23
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;

#define DEBUG() printf("Checkpoint Reached\n");

const int MOD = 1000000007;

int m;
int a[1000002];

int solve(int n, int a, int b) {
    vvl T(n+2, vl(m+2));
    for (int i = 1; i <= m; i++) {
        T[0][i] = int(abs(i-b) <= 1);
    }
    for (int i = 0; i <= n; i++) {
        T[i][0] = 0;
        T[i][m+1] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            T[i][j] = T[i-1][j-1] + T[i-1][j] + T[i-1][j+1];
            T[i][j] %= MOD;
        }
    }
    return T[n][a];
}

int main () {
    int n; cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 1; a[n+1] = 1;

    for (int i = 1; i <= n-1; i++) {
        if (a[i] > 0 && a[i+1] > 0 && abs(a[i] - a[i+1]) > 1) {cout << "0\n"; return 0;}
    }
    
    if (n == 1) {
        if (a[1] > 0) {cout << "1\n"; return 0;}
        else {cout << m << '\n'; return 0;}
    }

    int L, R;

    L = 0;
    vector<pair<int, int>> intls;

    for (int i = 1; i <= n+1; i++) {
        if (a[i] == 0 && a[i-1] > 0) {
            L = i;
        }
        if (a[i] > 0 && a[i-1] == 0) {
            intls.push_back({L, i});
        }
    }

    ll count = 1;
    ll icount;

    if (intls.size() == 1 && intls[0].first == 1 && intls[0].second > n) {
        ll tot = 0;
        for (int a1 = 1; a1 <= m; a1 ++) {
            for (int b1 = 1; b1 <= m; b1 ++) {
                tot += solve(n-2, a1, b1);
            }
        }
        cout << tot % MOD << '\n'; return 0;
    }

    for (auto i: intls) {
        L = i.first;
        R = i.second;
        icount = 1;
        if (L > 1 && R <= n) {
            count *= solve(R-L, a[L-1], a[R]); count %= MOD;
        }
        if (L == 1) {
            icount = 0;
            for (int j = 1; j <= m; j++) {
                icount += solve(R-L-1, j, a[R]);
            }
            icount %= MOD; count *= icount; count %= MOD;
        }
        if (R > n) {
            icount = 0;
            for (int j = 1; j <= m; j++) {
                icount += solve(R-L-1, j, a[L-1]);
            }
            icount %= MOD; count *= icount; count %= MOD;
        }
    }

    cout << count << endl;
}