/**
 * Cycle Finding
 * url: https://cses.fi/problemset/task/1197
 * date: 1/24/2023
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e13;

int n, m;
vector<tuple<int, int, ll>> edges;
vector<ll> dist(2501, INF);
vector<int> previ(2501);

int main () {
    cin >> n >> m;
    int a, b; ll c;
    while (m--) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    for (int i = 1; i <= n; i++) {
        edges.push_back({0, i, 0});
    }

    // BF
    dist[0] = 0;
    for (int k = 0; k < n - 1; k++) {
        for (auto e: edges) {
            tie(a, b, c) = e;
            if (dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                previ[b] = a;
            }
        }
    }

    for (auto e: edges) {
        tie(a, b, c) = e;
        if (dist[a] + c < dist[b]) {
            cout << "YES\n";
            previ[b] = a;

            for (int i = 0; i < n; i++) b = previ[b];

            int d = b;
            vector<int> path;
            path.push_back(b);
            while (previ[d] != b && previ[d] > 0) {
                d = previ[d];
                path.push_back(d);
            }
            path.push_back(b);
            reverse(path.begin(), path.end());
            for (auto i: path) {
                cout << i << " ";
            }
            cout << "\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}