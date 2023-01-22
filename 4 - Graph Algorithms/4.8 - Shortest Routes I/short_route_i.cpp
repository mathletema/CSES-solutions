/**
 * Shortest Routes I
 * url: https://cses.fi/problemset/task/1671
 * date: 1/22/2023
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
/******************************************/
 
const ll INF = 9223372036854775807;
 
int n, m;
vector<vector<pair<int, ll>>> adj(1e5+1);
vector<ll> dist(2e5+1, INF);
vector<bool> vis(1e5+1, false);

void dijkstra() {
 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>> Q;
 
    dist[1] = 0;
    Q.push({0, 1});
 
    while (!Q.empty()) {
        int u = Q.top().second; Q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto i: adj[u]) {
            int v = i.first;
            ll w = i.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                Q.push({-dist[v], v});
            }
        }
    }
 
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}
 
int main () {
    cin >> n >> m;
 
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    dijkstra();
}