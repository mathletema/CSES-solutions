/**
 * Missing Number
 * url: https://cses.fi/problemset/task/1083
 * data: 12/31/2022
*/

#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;
    long long c = 0;
    int x = 0;
    for (int i = 1; i < n; i++) {
        cin >> x;
        c += x;
    }
    long long t = n;
    t *= (n+1);
    t = t / 2;
    cout << t - c << endl;
}