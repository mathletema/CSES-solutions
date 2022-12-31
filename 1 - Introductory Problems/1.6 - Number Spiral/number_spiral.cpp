/**
 * Number Spiral
 * url: https://cses.fi/problemset/task/1071
 * data: 12/31/2022
*/

#include <bits/stdc++.h>

using namespace std;

long long solve(int x, int y) {
    long long l;
    if (x == y) {
        l = x;
        l *= (x - 1);
        l += 1;
        return l;
    }
    if (x > y) {
        if (x % 2 == 0) {
            l = x - 1;
            l *= (x-1);
            l += y;
            return l;
        }
        else {
            l = x;
            l *= x;
            l += 1 - y;
            return l;
        }
    }
    if (x < y) {
        if (y % 2 == 0) {
            l = y; l *= y;
            l += 1 - x;
            return l;
        }
        else {
            l = (y-1); l *=  (y - 1);
            l += x;
            return l;
        }
    }
    return -1;
}

int main () {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> y >> x;
        cout << solve(x, y) << endl;
    }
}