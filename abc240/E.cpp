/**
 *      Author:  nicksms
 *      Created: 01.06.2023 20:21:37
**/

#include <bits/stdc++.h>
using namespace std;
struct node {
    int id; 
    set<int> e;
};

void dfs(int id, vector<node> &v) {
    for (int x : v[id].e) {
        v[x].e.erase(id);
        dfs(x, v);
    }
}

int endps[200001][2];

int dfs2(int id, int offset, vector<node> &v) {
    int cur = offset;
    for (int x : v[id].e) {
        cur = dfs2(x, cur, v);
    }
    if (v[id].e.size() >= 1) cur--;
    endps[id][0] = offset;
    endps[id][1] = cur;
    return cur+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<node> ns(n+2);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ns[u].e.insert(v);
        ns[v].e.insert(u);
    }
    dfs(1, ns);
    dfs2(1, 1, ns);
    for (int i = 1; i <= n; i++) {
        cout << endps[i][0] << " " << endps[i][1] << endl;
    }

    return 0;
}