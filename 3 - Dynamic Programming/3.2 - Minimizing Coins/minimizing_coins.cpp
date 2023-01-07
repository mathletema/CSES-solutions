/**
 * Minimizing Coins
 * url: https://cses.fi/problemset/task/1634
 * date: 1/2/2023
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main () {
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> T(n, vector<int> (x + 1, INF));

    for (int i = 0; i < n; i++) T[i][0] = 0;

    int res; 
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            res = INF;
            if (i >= 1) res = min(res, T[i-1][j]);
            if (j >= c[i]) res = min(res, T[i][j-c[i]] + 1);
            T[i][j] = res;
        }
    }
    res = T[n-1][x];
    if (res == INF) cout << -1 << endl;
    else cout << res;
    return 0;
}