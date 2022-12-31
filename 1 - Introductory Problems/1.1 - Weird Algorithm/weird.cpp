/**
 * Weird Algorithm
 * url: https://cses.fi/problemset/task/1068
 * data: 12/31/2022
*/

#include <bits/stdc++.h>

using namespace std;

int main () {
    long long n; cin >> n;
    while (n > 1) {
        cout << n << " ";
        if ((n %2 == 0)) n = n >> 1;
        else n = n + (n << 1) + 1;
    }
    cout << n << endl;
}