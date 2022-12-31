/**
 * Dice Combinations
 * url: https://cses.fi/problemset/result/5209477/
 * date: 12/31/2022
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> T(2e6, 0);
const int mod = 1e9 + 7;

int main () {
    T[1] = 1;
    T[2] = 2;
    T[3] = 4;
    T[4] = 8;
    T[5] = 16;
    T[6] = 32;
    
    int n; cin >> n;
    if (n > 6) {
        for (int i = 7; i <= n; i++) {
            for (int j = 1; j <= 6; j++) {
                T[i] += T[i - j];
                if (T[i] >= mod) T[i] -= mod;
            }
        }
    }
    cout << T[n] << endl;
}