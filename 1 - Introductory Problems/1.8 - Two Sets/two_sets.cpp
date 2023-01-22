/**
 * Two Sets
 * url: https://cses.fi/problemset/task/1092
 * date: 1/20/23
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
bool vis[1000001] = {false};

int main () {
    cin >> n;
    ll s = n * (n + 1); s /= 2;
    if (s & 1 == 1) {
        cout << "NO\n"; return 0;
    }
    cout << "YES\n";
    s /= 2;
    int c = n;
    
    vector<int> s1;

    while (s > c) {
        s1.push_back(c);
        s -= c;
        c -= 1;
    }

    cout << s1.size() + 1 << "\n";
    for (auto i: s1) cout << i << " ";
    cout << s << "\n";
    cout << n - s1.size() - 1 << "\n";
    
    while (c > 0) {
        if (c != s) cout << c << " ";
        c -= 1;
    }
    cout << "\n";
    
}