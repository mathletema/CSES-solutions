/**
 * Coin Combinations I
 * url: https://cses.fi/problemset/task/1635
 * date: 1/2/2023
*/

#include <bits/stdc++.h>

using namespace std;

void print_vi(vector<int> in) {for (int i = 0; i < in.size(); i++) {cout << in[i] << " ";} cout << endl;}
void print_vvi(vector<vector<int>> in) {for (int i = 0; i < in.size(); i++) print_vi(in[i]);}

int mod = 1e9 + 7;

int n, x;
vector<int> c(100);
vector<int> T(1e6 + 1, 0);

int main () {
    cin >> n >> x;

    for (int i = 0; i < n; i++) cin >> c[i];

    T[0] = 1;

    long long res;

    for (int j = 1; j <= x; j++) {
        res = 0;

        for (int k = 0; k < n; k++) {
            res += ((j >= c[k]) ? T[j - c[k]] : 0);
        }

        res %= mod;

        T[j] = res;
    }

    cout << T[x] << endl;
}