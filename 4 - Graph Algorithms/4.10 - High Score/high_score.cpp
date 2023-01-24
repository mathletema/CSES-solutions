/**
 * High Score
 * url: https://cses.fi/problemset/task/1673
 * data: 1/23/2022
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = -6e12;

vector<vector<int>> adj(2501);
vector<vector<int>> adj_T(2501);
vector<tuple<int, int, ll>> edges;


vector<bool> vis1(2501, false);
vector<bool> vis2(2501, false);
vector<bool> G_V(2501, false);

vector<ll> dist(2501, INF);

int n, m;

int main () {
    cin >> n >> m;
    
    int a, b; ll x;
    while (m--) {
        cin >> a >> b >> x;
        adj[a].push_back(b);
        adj_T[b].push_back(a);
        edges.push_back({a, b, x});
    }

    // BFS from node 1;
    queue<int> Q1;

    vis1[1] = true;
    Q1.push(1);
    while (!Q1.empty()) {
        int u = Q1.front(); Q1.pop();
        for (auto v: adj[u]) {
            if (vis1[v]) continue;
            vis1[v] = true;
            Q1.push(v);
        }
    }

    // BFS from node 2
    queue<int> Q2;
    
    vis2[n] = true;
    Q2.push(n);
    while(!Q2.empty()) {
        int u = Q2.front(); Q2.pop();
        for (auto v: adj_T[u]) {
            if (vis2[v]) continue;
            vis2[v] = true;
            Q2.push(v);
        }
    }

    // New graph
    for (int i = 1; i <= n; i++) {
        G_V[i] = vis1[i] && vis2[i];
    }

    // Belman Ford
    dist[1] = 0;
    for (int k = 0; k < n-1; k++) {
        for (auto e : edges) {
            int a, b; ll c;
            tie(a, b, c) = e;
            if (G_V[a] && G_V[b]) dist[b] = max(dist[b], dist[a] + c);
        }
    }

    for (auto e : edges) {
        int a, b; ll c;
        tie(a, b, c) = e;
        if (G_V[a] && G_V[b] && dist[a] + c > dist[b]) {
            cout << "-1\n"; return 0;
        }
    }

    cout << dist[n] << '\n';
}