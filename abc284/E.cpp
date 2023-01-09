/**
 *      Author:  nicksms
 *      Created: 01.07.2023 06:30:55
**/

#include <bits/stdc++.h>
using namespace std;
struct node {
    int id;
    vector<int> edges;
};

int tot = 0;

void dfs(int i, const vector<node> &v, set<int> &vis) {
    // cout << "test" << i << vis.size() << vis.count(1) << endl;
    tot++;
    vis.insert(i);
    if (tot >= 1000000) return;
    for (int x : v[i].edges) {
        if (vis.count(x) == 0) {
            dfs(x,v,vis);
            if (tot >= 1000000) return;
        }
    }
    vis.erase(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<node> v(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].edges.push_back(b);
        v[b].edges.push_back(a);
        // cout << "read" << endl;
    }
    set<int> vis;
    dfs(1,v,vis);
    cout << tot << endl;
    
    return 0;
}