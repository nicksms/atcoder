/**
 *      Author:  nicksms
 *      Created: 01.05.2023 17:29:25
**/

#include <bits/stdc++.h>
using namespace std;
struct node {
    int id;
    int color = -1;
    vector<int> edges;
    int c[2] = {0,0};
};

bool dfs (int id, int col, vector<node>& v, vector<bool>& vis, int par) {
    v[par].c[col] += 1;
    v[id].color = col;
    vis[id] = true;
    for (int j : v[id].edges) {
        if (v[j].color == col) {
            return false;
        }
        if (!vis[j]) {
            if (!dfs(j, 1-col, v, vis, par)) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<node> v(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) v[i].id = i;

    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        v[s].edges.push_back(t);
        v[t].edges.push_back(s);
    }
    long long ss = 0;
    long long s = 0;
    long long inner = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (!dfs(i, 0, v, vis, i)) {
                cout << "0\n";
                return 0;
            }
            ss += (0LL + v[i].c[0] + v[i].c[1]) * (0LL + v[i].c[0] + v[i].c[1]);
            s += 0LL + v[i].c[0] + v[i].c[1];
            inner += (0LL + v[i].c[0])*v[i].c[1];
        }
    }
    long long across = s*s - ss;
    across /= 2;
    cout << across + inner - m << endl;
    return 0;
}