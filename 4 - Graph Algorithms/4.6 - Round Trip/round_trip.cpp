/**
 * Round Trip
 * url: https://cses.fi/problemset/task/1669
 * date: 1/6/2023
*/

#include <bits/stdc++.h>

using namespace std;

/**********************************************/

int n, m;
vector<vector<int>> adj(1e6);

vector<bool> gray(1e6, false);
vector<bool> black(1e6, false);
vector<int> pre(1e6);

void debug() {
    for (int i = 1; i <= n; i++) {
        if (black[i]) cout << i << ". black\n";
        else if (gray[i]) cout << i << ". gray\n";
        else cout << i << ". white\n";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++ ) {
        cout << pre[i] << " ";
    }
    cout << "\n\n";
}

int dfs(int s) {
    if (gray[s]) return 0;
    gray[s] = true;

    // debug();

    for (auto u: adj[s]) {
        if (gray[u] && !black[u] && u != pre[s]) {
            // printf("Cycle Detected\n", s, u);
            int t = s;
            vector<int> cycl = {u, t};
            while (t != u) {
                t = pre[t];
                cycl.push_back(t);
            }
            cout << cycl.size() << endl;
            for (auto i : cycl) cout << i << " ";
            cout << endl;
            return 1;
        }
        if (!gray[u]) {
            pre[u] = s;
            if (dfs(u)) return 1;
        }
    }

    black[s] = true;

    // debug();

    return 0;
}


void solve () {
    int t, u; u = 1;
    bool worked = false;
    while (u <= n) {
        if (!gray[u]) pre[u] = 0;
        if (dfs(u)) return;
        u++;
    }
    cout << "IMPOSSIBLE\n";
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

    return 0;
}