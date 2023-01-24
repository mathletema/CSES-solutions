/**
 * Flight Discount
 * url: https://cses.fi/problemset/task/1195
 * date: 1/23/2023
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e15;

int n, m;
vector<vector<pair<int, ll>>> adj(2e5+1);

vector<bool> vis(2e5+1, false);
vector<ll> dist(2e5+1, INF);

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
 
    cout << dist[2 * n] << endl;
}

int main () {
    cin >> n >> m;

    int a, b; ll c;
    while (m--) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[n+a].push_back({n+b, c});
        adj[a].push_back({n+b, (ll) c / 2});
    }

    dijkstra();
}