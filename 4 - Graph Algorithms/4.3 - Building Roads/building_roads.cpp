/**
 * Labrynth
 * url: https://cses.fi/problemset/task/1666
 * data: 12/14/2022
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <algorithm> 

using namespace std;


void print_vi(vector<int> in) {for (int i = 0; i < in.size(); i++) {cout << in[i] << " ";} cout << endl;}
void print_vvi(vector<vector<int>> in) {for (int i = 0; i < in.size(); i++) print_vi(in[i]);}

// main code

void dfs(int u, vector<bool>& vis, vector<vector<int>>& adj) {
    vis[u] = true;
    int v;
    for (int i = 0; i < adj[u].size(); ++i) {
        v = adj[u][i];
        if (!vis[v]) {
            dfs(v, vis, adj);
        }
    }
}

int main () {
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);

    int u, v;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n);

    int count = 0;
    vector<int> SCC;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj);
            count++;
            SCC.push_back(i);
        }
    }
    
    cout << (count - 1) << "\n";

    for (int i = 0; i < count - 1; i++) {
        cout << SCC[i] + 1 << " " << SCC[i+1] + 1 << "\n";
    }
}