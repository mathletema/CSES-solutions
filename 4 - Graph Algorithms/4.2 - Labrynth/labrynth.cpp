/**
 * Labrynth
 * url: https://cses.fi/problemset/task/1193
 * data: 12/13/2022
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <algorithm> 

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print_vi(vi in) {for (int i = 0; i < in.size(); i++) {cout << in[i] << " ";} cout << endl;}
void print_vvi(vvi in) {for (int i = 0; i < in.size(); i++) print_vi(in[i]);}

// main code

typedef struct {
    vi val;
    vi *prev;
} node;

void f(vvi grid, int sx, int sy, int fx, int fy, int *count, string *path) {
    int N = grid.size(); int M = grid[0].size();
    vi prevs[N][M];
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j++) {
            prevs[i][j] = {-2, -2};
        }
    }
    prevs[sx][sy] = {-1, -1};

    queue<vi> Q;
    Q.push({sx, sy});

    // print_vvi(grid);

    grid[sx][sy] = 0;

    int xa, ya, xb, yb;

    while (!Q.empty()) {
        vi a = Q.front(); Q.pop();
        xa = a[0]; ya = a[1];

        // printf("Working on %d, %d\n", xa, ya);

        for (int i = 0; i <= 1; i++) {
            for (int j = -1; j <= 1; j+=2) {
                xb = xa;
                yb = ya;
                if (i == 0) xb += j;
                else yb += j;
                
                // printf("Checking on %d, %d\n", xb, yb);

                if (0 <= xb && xb < N && 0 <= yb && yb < M && grid[xb][yb] == 1) {
                    Q.push((vi) {xb, yb});
                    // printf("Works! %d, %d\n", xb, yb);
                    grid[xb][yb] = 0;
                    prevs[xb][yb] = {xa, ya};
                }
            }
        }
    }


    int c = 0;
    string d = "";
    
    int cx, cy; cx = fx; cy = fy;
    vi p = prevs[cx][cy];

    // printf("Got here!");

    // print_vi (p);
    if (cx > p[0]) d += "D";
    if (cx < p[0]) d += "U";
    if (cy > p[1]) d += "R";
    if (cy < p[1]) d += "L";

    while (p[0] >= 0 && p[1] >= 0) {
        cx = p[0]; cy = p[1];
        p = prevs[cx][cy];
        // print_vi (p);
        if (cx > p[0]) d += "D";
        if (cx < p[0]) d += "U";
        if (cy > p[1]) d += "R";
        if (cy < p[1]) d += "L";
        c++;
    }
    if (p[0] == -2) {
        *count = -1;
    } else {
        reverse(d.begin(), d.end());
        *count = c;
        *path = d.substr(2);
    }
};

int main() {
    int n, m;
    int sx, sy, fx, fy;
    cin >> n >> m;
    vvi input;
    for (int i = 0; i < n; i++) {
        vi row;
        string t;
        cin >> t;
        for(int j = 0; j < m; j++) {
            if (t[j] == 'A') {sx = i; sy = j;}
            if (t[j] == 'B') {fx = i; fy = j;}

            if (t[j] == '#') row.push_back(0);
            else {
                row.push_back(1);
            }
        }
        input.push_back(row);
    }
    int count; string path;
    f(input, sx, sy, fx, fy, &count, &path);
    if (count < 0) cout << "NO" << endl;
    else {
        cout << "YES" << '\n'
            << count << '\n'
            << path << '\n';
    }
}