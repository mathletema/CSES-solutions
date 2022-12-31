/**
 * Permutations
 * url: https://cses.fi/problemset/task/1070
 * data: 12/31/2022
*/

#include <bits/stdc++.h>

using namespace std;

int main () {
    int N; cin >> N;
    if (N == 1) { cout << "1\n"; return 0; }
    if (N <= 3) { cout << "NO SOLUTION\n"; return 0; }
    if (N == 4) { cout << "2 4 1 3\n"; return 0;}
    vector<int> A(N);
    int c = 1;
    int i = 0;
    while (i < N) {
        A[i] = c;
        c += 1;
        i += 2;
    }
    i = 1;
    while (i < N) {
        A[i] = c;
        c += 1;
        i += 2;
    }
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << "\n";
}