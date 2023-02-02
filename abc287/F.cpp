/**
 *      Author:  nicksms
 *      Created: 01.31.2023 11:36:42
**/

#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>
using mint = atcoder::modint998244353;
using namespace std;
#define ll long long
vector<mint> cmany(const vector<vector<mint>>& v, int l, int r, int cap) {
    // cout << "test " << l << " " << r << " " << v[l].size() << endl;
    if (r-l==1) return v[l];
    vector<mint> c = atcoder::convolution(cmany(v, l, (l+r)/2, cap),cmany(v, (l+r)/2, r, cap));
    if (c.size() > cap) c.resize(cap, mint{0});
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<vector<mint>> nt(N+1);
    vector<vector<mint>> yt(N+1);
    vector<vector<int>> outs(N+1);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        outs[a].push_back(b);
        outs[b].push_back(a);
    }
    auto dfs = [&](int x, int from, auto &&dfs) -> void {
        for (int v : outs[x]) if (v != from) dfs(v,x,dfs);
        if ((outs[x].size() == 1 && x != 1) || (outs[x].size() == 0 && x == 1)) { // leaf
            nt[x].push_back(1);
            yt[x].push_back(1);
            return;
        }
        int s = outs[x].size() + (x == 1 ? 0 : -1);
        vector<vector<mint>> ntp(s);
        vector<vector<mint>> ytp(s);
        for (int i = 0, j = 0; i < outs[x].size(); i++) {
            if (outs[x][i] == from) continue;
            for (int k = 0; k < max(nt[outs[x][i]].size(), yt[outs[x][i]].size()+1); k++) {
                mint t = 0;
                if (k < nt[outs[x][i]].size()) t += nt[outs[x][i]][k];
                if (k > 0 && k < yt[outs[x][i]].size()+1) t += yt[outs[x][i]][k-1];
                ntp[j].push_back(t);
                if (k > 0 && k < yt[outs[x][i]].size()+1) t -= yt[outs[x][i]][k-1];
                if (k < yt[outs[x][i]].size()) t += yt[outs[x][i]][k];
                ytp[j].push_back(t);
                if (k < yt[outs[x][i]].size()) t -= yt[outs[x][i]][k];
            }
            j++;
        }
        nt[x] = cmany(ntp, 0, ntp.size(), 5002);
        yt[x] = cmany(ytp, 0, ytp.size(), 5002);
    };
    dfs(1, 0, dfs);
    nt[1].resize(5002);
    yt[1].resize(5002);
    for (int i = 1; i <= N; i++) {
        cout << (nt[1][i] + yt[1][i-1]).val() << "\n";
    }
    return 0;
}