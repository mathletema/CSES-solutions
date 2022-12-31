/**
 * Repetitions
 * url: https://cses.fi/problemset/task/1069
 * data: 12/31/2022
*/

#include <bits/stdc++.h>

using namespace std;

int main () {
    string s; cin >> s;
    int n = s.size();
    int i = 1;
    char c = s[0]; char d;
    int max = 1; int cur = 1;
    while (i < n) {
        d = s[i];
        if (d == c) {
            cur += 1;
        }
        else {
            c = d;
            cur = 1;
        }
        if (cur > max) max = cur;
        i++;
    }
    cout << max;
}