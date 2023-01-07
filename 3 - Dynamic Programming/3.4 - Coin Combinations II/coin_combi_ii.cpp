/**
 * Coin Combinations II
 * url: https://cses.fi/problemset/task/1636
 * date: 1/2/2023
*/

#include <bits/stdc++.h>

using namespace std;

void print_vi(vector<int> in) {for (int i = 0; i < in.size(); i++) {cout << in[i] << " ";} cout << endl;}
void print_vvi(vector<vector<int>> in) {for (int i = 0; i < in.size(); i++) print_vi(in[i]);}

int mod = 1e9 + 7;

int n, x;
vector<int> c(100);
// vector<vector<int>> T(100, vector<int>(1e6 + 1, 0));

int main () {
    cin >> n >> x;

    for (int i = 0; i < n; i++) cin >> c[i];
    
    int a1, a2;

    vector<vector<int>> T(n, vector<int>(x+1, 0));

    for (int i = 0; i < n; i++) T[i][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            a1 = (i >= 1) ? T[i - 1][j] : 0;
            a2 = (j >= c[i]) ? T[i][j - c[i]] : 0;
            T[i][j] = (a1 + a2) % mod;
            // print_vvi(T);
            // cout << "\n\n";
        }
    }

    cout << T[n-1][x] << endl;
}