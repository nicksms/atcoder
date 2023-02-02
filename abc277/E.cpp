/**
 *      Author:  nicksms
 *      Created: 02.02.2023 09:59:27
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pib = pair<int,bool>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K; cin >> N >> M >> K;
    vector<set<pib>> adj(N+1);
    for (int i = 0; i < M; i++) {
        int u, v, a; cin >> u >> v >> a;
        adj[u].emplace(v,(bool)a);
        adj[v].emplace(u,(bool)a);
    }
    vector<bool> s(N+1);
    for (int i = 1; i <= K; i++) {
        int a; cin >> a;
        s[a] = true;
    }
    set<pib> vis;
    priority_queue<pair<int,pib>,vector<pair<int,pib>>, greater<pair<int,pib>>> proc; 
    map<pib, int> best; 
    proc.emplace(0,pib{1, true});
    vis.emplace(1, true);
    auto q = [&](int d, int v, bool b, bool o) -> void {
        if (o || !vis.count(pib{v,b})) {
            vis.emplace(v,b);
            proc.emplace(d,pib{v,b});
        }
    }; 
    while (proc.size() > 0) {
        auto [d, p] = proc.top();
        auto [v, b] = p;
        proc.pop();
        if (v == N) {
            cout << d << "\n";
            return 0;
        }
        if (best.count(pib{v,b})) continue;
        if (s[v] && !best.count(pib{v,!b})) q(d, v, !b, true);
        best[pib{v,b}] = d;
        for (auto [vv, a] : adj[v]) if ((a == b) && !vis.count(pib{vv,b})) {
            q(d+1, vv, b, false);
        }
    }
    cout << "-1\n";
    return 0;
}