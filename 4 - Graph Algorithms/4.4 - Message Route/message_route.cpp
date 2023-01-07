/**
 * Message Route
 * url: https://cses.fi/problemset/task/1667
 * date: 1/6/2023
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi; 

/*************************************************/

const int INF = 2147483647;

int n; int m;
vector<vi> adj(1e5 + 2);
vi dist(1e5 + 2, INF);
vector<bool> vis(1e5 + 2, false);
vector<int> previ(1e5, -1);

void bfs(vector<vi> &adj) {
    dist[1] = 0;
    vis[1] = true;
    previ[1] = 0;
    queue<int> Q;
    Q.push(1);
    int u;
    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        for (auto v: adj[u]) {
            if (! vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                previ[v] = u;
                Q.push(v);
            }
        }
    }

    if (vis[n]) {
        cout << dist[n] + 1 << endl;
        vi path;
        int u = n;
        while (u != 0) {
            path.push_back(u);
            u = previ[u];
        }
        reverse(path.begin(), path.end());
        for (auto i: path) cout << i << " "; cout << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}


int main () {
    cin >> n >> m;
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bfs(adj);
}