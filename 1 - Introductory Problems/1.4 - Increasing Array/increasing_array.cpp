/**
 * Increasing Array
 * url: https://cses.fi/problemset/task/1094
 * data: 12/31/2022
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> A (2e5);

int main () {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];

    int i = 1;
    int max = A[0];
    long long c = 0;
    
    while (i < n) {
        if (A[i] > max) max = A[i];
        if (A[i] < max) c += max - A[i];
        i++;
    }
    cout << c << endl;
}