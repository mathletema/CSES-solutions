/**
 * Removing Digits
 * url: https://cses.fi/problemset/task/1637
 * date: 1/2/2023
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;
vector<int> T(1e6 + 1, 1e9);

int main () {
    
    cin >> n;


    for (int i = 0; i < 10; i++) T[i] = 1;

    int dig;

    for (int i = 10; i <= n; i++) {
        for (int j = 0; j <= 6; j++) {
            dig = int(i / (pow(10, j))) % 10;
            if (dig != 0) T[i] = min(T[i], T[i - dig] + 1);
        }
    }

    cout << T[n] << endl;
}
