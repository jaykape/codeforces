/*
Given a forest of nodes 1, 2, ..., n
for each query v, p find the number of nodes with the same p-th ancestor as v.

Input
L1      : n
L2      : r1 r2 ... rn   : parent array
L3      : qn             : number of queries
m lines : v, p

Constraint n <= 1e5, qn <= 1e5
*/

#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

int n, qn;

vector<vector<int>> childs;
vector<array<int, LOG>> up;
vector<int> depth, tin, tout;

vector<vector<int>> nodes_at_depth;

int timer = 0;

void dfs(int u) {
    tin[u] = ++timer;
    nodes_at_depth[depth[u]].push_back(tin[u]);
    for (int j = 1; j < LOG; ++j) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }
    for (int v : childs[u]) {
        depth[v] = depth[u] + 1;
        dfs(v);
    }
    tout[u] = timer;
}

int jump(int u, int k) {
    for (int j = 0; j < LOG; ++j) {
        if ((k >> j) & 1)
            u = up[u][j];
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int N = n + 1;
    childs.resize(N);
    up.resize(N);
    depth.resize(N);
    tin.resize(N), tout.resize(N);
    nodes_at_depth.resize(N);

    up[0].fill(0);

    for (int v = 1; v <= n; ++v) {
        int p;
        cin >> p;
        up[v][0] = p;
        childs[p].push_back(v);
    }

    depth[0] = 0;
    dfs(0);

    cin >> qn;
    for (int i = 0; i < qn; ++i) {

        int v, p;
        cin >> v >> p;

        int a = jump(v, p);

        if (a == 0) {
            cout << "0 ";
            continue;
        }

        auto &nd = nodes_at_depth[depth[v]];
        int cnt = upper_bound(nd.begin(), nd.end(), tout[a]) - lower_bound(nd.begin(), nd.end(), tin[a]) - 1;

        cout << cnt << ' ';
    }
}