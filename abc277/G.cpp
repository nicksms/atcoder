/**
 *      Author:  nicksms
 *      Created: 02.01.2023 14:14:33
**/

#include <bits/stdc++.h>
#include <atcoder/modint>
using mint = atcoder::modint998244353;
using namespace std;
#define ll long long
mint p[3001][3001]; // N, K
mint pa[3001][3001];
mint ps[3001][3001];
mint dinv[3001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K; cin >> N >> M >> K;
    vector<int> degrees(N+1);
    vector<pair<int,int>> edges(M);
    for (int i = 0; i < M; i++) cin >> edges[i].first >> edges[i].second;
    vector<int> C(N+1);
    for (int i = 1; i <= N; i++) cin >> C[i];
    for (auto [a,b] : edges) degrees[a]++, degrees[b]++;
    for (int i = 1; i <= N; i++) dinv[i] = 1/mint{degrees[i]};
    p[1][0] = 1;
    mint tot = 0;
    for (int k = 1; k <= K; k++) {
        for (auto [a,b] : edges) {
            p[a][k] += dinv[b]*p[b][k-1];
            p[b][k] += dinv[a]*p[a][k-1];
            pa[a][k] += dinv[b]*(pa[b][k-1] + (1-C[a])*p[b][k-1]);
            pa[b][k] += dinv[a]*(pa[a][k-1] + (1-C[b])*p[a][k-1]);
            ps[a][k] += dinv[b]*( C[a] ? ps[b][k-1] : ps[b][k-1] + 2*pa[b][k-1] + p[b][k-1]);
            ps[b][k] += dinv[a]*( C[b] ? ps[a][k-1] : ps[a][k-1] + 2*pa[a][k-1] + p[a][k-1]);
        }
        for (int v = 1; v <= N; v++) if (C[v]) tot += ps[v][k];
    }
    cout << tot.val() << "\n";
    return 0;
}