/**
 *      Author:  nicksms
 *      Created: 01.09.2023 16:45:10
 *      Possibly learned how to use FFT now.
**/

#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>
#define ll long long
using mint = atcoder::modint998244353;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, A; cin >> N >> A;
    vector<mint> C(N+1);
    C[0] = mint{1};
    for (int i = 1; i <= N; i++) {
        C[i] = C[i-1]*(mint{A}-i+1)/mint{i};
    }
    auto f = [&](int l, int r, const vector<mint> &g, auto &&f) -> vector<mint> { // assume only given indices [l,r) of g for [l,r) per editorial, still don't have a solid handle on how this works
        if (r-l == 1) return {1,g[0]};
        int m = (l+r)/2;
        vector<mint> lm = f(l,m,vector<mint>(g.begin(), g.begin()+(m-l)),f);
        vector<mint> gm = atcoder::convolution(g, lm);
        gm.erase(gm.begin(), gm.begin()+(m-l));
        gm.resize(r-m);
        return atcoder::convolution(lm, f(m,r,gm,f));
    };
    cout << (N <= 2 ? C[N].val() : atcoder::convolution(C, f(2, N, vector<mint>(C.begin() + 2, C.end()), f))[N].val()) << "\n";
    return 0;
}