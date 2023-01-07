/**
 * Building Teams
 * url: https://cses.fi/problemset/task/1668
 * date: 1/6/2023
*/

#include <bits/stdc++.h>

using namespace std;

/******************************************/

int n, m;
vector<vector<int>> adj(1e6);

vector<bool> color(1e6);
vector<bool> vis(1e6, false);

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    bool col = color[u];
    for (auto v: adj[u]) {
        color[v] = ! col;
        dfs(v);
    }
}

int check () {
    for (int u = 1; u <= n; u++) {
        for (auto v: adj[u]) {
            if (color[u] == color[v]) return 0;
        }
    }
    return 1;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    if (!check()) cout << "IMPOSSIBLE\n";

    for (int i = 1; i <= n; i++) {
        if (color[i]) cout << "1 ";
        else cout << "2 ";
    }
    cout << endl;
}

int main () {
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve();
}