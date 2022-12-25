/**
 * Monsters
 * url: https://cses.fi/problemset/task/1194
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

// begin code

void f(int n, int m, vector<vector<bool>> grid, vector<int> monsters, int start, vector<int> end) {
    // Create adj
    int x1, y1;
    vector<vector<int>> adj(m * n); 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j]) {
                // for each point
                for (int r = 0; r < 2; r++) {
                    for (int s = -1; s <= 1; s+=2) {
                        if (r == 0) {x1 = i + s; y1 = j;}
                        else {x1 = i, y1 = j + s;}
                        // for each adj point
                        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && grid[x1][y1]) {
                            adj[m * i + j].push_back(m * x1 + y1);             
                        }                         
                    }
                }
            }
        }
    }

    // BFS for monsters

    vector<int> m_dist(m * n, m * n + 10);
    queue<int> m_Q;
    vector<bool> m_vis(m * n, false);

    for (int i: monsters) {
        m_dist[i] = 0;
        m_Q.push(i);
        m_vis[i] = true;
    }

    int u;

    while (!m_Q.empty()) {
        u = m_Q.front(); m_Q.pop();
        for (int v: adj[u]) {
            if (! m_vis[v]) {
                m_vis[v] = true;
                m_dist[v] = m_dist[u] + 1;
                m_Q.push(v);
            }
        }
    }

    // BFS for start;
    vector<int> s_dist(m * n, m * n + 10);
    vector<int> prev(m * n, -1);
    queue<int> s_Q;
    vector<bool> s_vis(m * n, false);

    s_Q.push(start);
    s_dist[start] = 0;
    s_vis[start] = true;

    while (!s_Q.empty()) {
        u = s_Q.front(); s_Q.pop();
        for (int v: adj[u]) {
            if (! s_vis[v]){
                s_vis[v] = true;
                s_dist[v] = s_dist[u] + 1;
                prev[v] = u;
                s_Q.push(v);
            }
        }
    }

    bool worked = false;
    int final;
    
    for (int e : end) {
        if (s_dist[e] < m_dist[e]) {
            worked = true;
            final = e;
        }
    }

    if (!worked) cout << "NO\n";
    else {
        cout << "YES\n";

        vector<int> path;

        while (final != start) {
            path.push_back(final);
            final = prev[final];
        }


        int N = path.size();
        cout << N << "\n";

        int c = start; int d;
        for (int j = N - 1; j >= 0; --j) {
            d = path[j];
            if (d - c == 1) cout << "R";
            if (d - c == - 1) cout << "L";
            if (d - c == m) cout << "D";
            if (d - c == -m) cout << "U";
            c = d;
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> grid(n);
    vector<int> monsters;
    vector<int> end;
    int start;

    string t_row;

    for (int i = 0; i < n; ++i) {
        cin >> t_row;
        for (int j = 0; j < m; ++j) {
            if (t_row[j] == '#') grid[i].push_back(false);
            else {
                grid[i].push_back(true);
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) end.push_back(m * i + j);
            }

            if (t_row[j] == 'M') monsters.push_back(m * i + j);
            if (t_row[j] == 'A') start = m * i + j;
        }
    }
    
    f(n, m, grid, monsters, start, end);

}