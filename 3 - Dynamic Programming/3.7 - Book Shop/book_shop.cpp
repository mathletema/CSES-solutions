/**
 * Book Shop
 * url: https://cses.fi/problemset/task/1158
 * 1/2/2023
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print_vi(vi vec) { for (int i : vec) cout << i << " "; cout << "\n"; }
void print_vvi(vvi vec) { for (vi i: vec) print_vi(i); }

/********************************************/

int n, x;
vi h(1001), s(1001);

vvi T(1001, vi(1e5+1, 0));

int main () {
    cin >> n >> x;

    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = h[0]; i <= x; i++) T[0][i] = s[0];

    for (int i = 1; i < n; i++) {
        for  (int j = 1; j <= x; j++) {
            T[i][j] = T[i-1][j];
            if (j - h[i] >= 0) T[i][j] = max(T[i][j], T[i-1][j - h[i]] + s[i]);
        }
    }

    cout << T[n-1][x] << endl;

}