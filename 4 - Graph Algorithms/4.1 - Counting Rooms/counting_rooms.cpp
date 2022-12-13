/**
 * Counting Rooms
 * url: https://cses.fi/problemset/submit/1192/
 * data: 12/13/2022
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

void print_vector_int(vector<int> in) {for (int i = 0; i < in.size(); i++) {cout << in[i] << " ";} cout << endl;}
void print_vvector_int(vector<vector<int>> in) {for (int i = 0; i < in.size(); i++) print_vector_int(in[i]);}

void bfs(int x, int y, vector<vector<int>> *grid) {
    queue<vector<int>> Q;
    vector<int> a;
    int xa, ya, xb, yb, n, m;
    n = grid->size();
    m = (*grid)[0].size();
    Q.push({x, y});
    (*grid)[x][y] = 0;
    while (!Q.empty()) {
        a = Q.front();
        xa = a[0];
        ya = a[1];
        Q.pop();
        for (int i = 0; i <= 1; i++) {
            for (int j = -1; j <= 1; j+=2) {
                xb = xa;
                yb = ya;
                if (i == 0) xb += j;
                else yb += j;
                if (0 <= xb && xb < n && 0 <= yb && yb < m && (*grid)[xb][yb] == 1) {
                    Q.push({xb, yb});
                    (*grid)[xb][yb] = 0;
                }
            }
        }
    }
}


int f(vector<vector<int>> grid) {
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                bfs(i, j, &grid);
                count ++;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> input;
    while (n--) {
        vector<int> row;
        string t;
        cin >> t;
        for(int i = 0; i < m; i++) {
            if (t[i] == '.') row.push_back(1);
            else row.push_back(0);
        }
        input.push_back(row);
    }
    cout << f(input) << endl;
}