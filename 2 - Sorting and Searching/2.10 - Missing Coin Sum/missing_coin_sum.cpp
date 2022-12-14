/**
 * Monsters
 * url: https://cses.fi/problemset/task/2183
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

long long f(vector<int> &num) {
    sort(num.begin(), num.end());
    int p = 0;
    long long max = 0;
    while (p < num.size()) {
        if (num[p] > max + 1) return max + 1;
        max = max + num[p++];
    }
    return max + 1;
}

int main () {
    int n;
    cin >> n;
    vector<int> num;
    int x;
    while (n--) {
        cin >> x;
        num.push_back(x);
    } 
    cout << f(num) << '\n';
}