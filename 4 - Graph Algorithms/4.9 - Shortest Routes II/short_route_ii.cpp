/**
 * Shortest Routes II
 * url: https://cses.fi/problemset/task/1672
 * date: 1/22/2023
*/
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll INF = 922337203685477580;
 
int n, m, q;
vector<vector<ll>> adj(501, vector<ll> (501, -1));
vector<vector<ll>> dist(501, vector<ll> (501, INF));

int main () {
    cin >> n >> m >> q;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }    

    int a, b; ll c;

    while (m--) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
 
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--) {
        cin >> a >> b;
        if (dist[a][b] == INF) cout << "-1\n";
        else cout << dist[a][b] << '\n';
    }
}   