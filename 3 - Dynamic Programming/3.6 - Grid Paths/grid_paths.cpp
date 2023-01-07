/**
 * Grid Paths
 * url: https://cses.fi/problemset/task/1638
 * 1/2/2023
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print_vi(vi vec) { for (int i : vec) cout << i << " "; cout << "\n"; }
void print_vvi(vvi vec) { for (vi i: vec) print_vi(i); }

/********************************************/

const int mod = 1e9 + 7;

int n;
vvi T(1001, vi(1001, 0));
vector<string> grid(1000);

int main () {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    if (grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }

    // vvi T(n+1, vi(n+1, 0));

    T[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            if (grid[i-1][j-1] == '.') T[i][j] = (T[i-1][j] + T[i][j-1]) % mod;
            // print_vvi(T);
            // cout << "\n\n"; 
        }
    }

    cout << T[n][n] << endl;

    return 0;
}