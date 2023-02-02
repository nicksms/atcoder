/**
 *      Author:  nicksms
 *      Created: 01.18.2023 10:20:52
**/

#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>
using mint = atcoder::modint998244353;
using namespace std;
#define ll long long
const int maxB = 10000000;
mint tfac[maxB+1];
mint tfaci[maxB+1];
mint G[200001];
mint stir[200001];

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
    tfaci[0] = tfaci[1] = tfac[0] = tfac[1] = 1;
    mint p2 = 2;
    for (int i = 2; i <= maxB; i++) {
        p2 *= 2;
        tfac[i] = (p2-1)*tfac[i-1];
        tfaci[i] = tfaci[i-1]/(p2-1);
    }
    // cout << tfaci[3].val() << " a" << endl; 
    int N, B; cin >> N >> B;
    if (N == 1) {
        cout << 1 << "\n";
        return 0;
    }
    vector<mint> lpart(N+1);
    vector<mint> rpart(N+1);
    for (int r = 0; r <= N; r++) {
        if (B - 1 - r >= 0) lpart[r] = mint{2}.pow(((0LL + r)*r+r)/2)*tfaci[B-1-r]*tfaci[r];
        rpart[r] = tfaci[r];
        // cout << lpart[r].val() << " " << rpart[r].val() << endl;
    }
    vector<mint> G = atcoder::convolution(lpart, rpart);
    G.resize(N+1, mint{0});
    for (int s = 0; s <= N; s++) {
        G[s] *= tfac[B-1]*tfac[s];
    }
    auto good = [&](int s) -> mint {
        vector<vector<mint>> fall(s);
        for (int i = 0; i < s; i++) {
            vector<mint> temp(2);
            temp[0] = -i;
            temp[1] = 1;
            fall[i] = temp;
        }
        // cout << fall.size() << endl;
        vector<mint> stir = cmany(fall, 0, s, s+1);
        stir.resize(s+1, mint{0});
        mint k = mint{2}.pow(B);
        mint all = 1;
        for (int i = 0; i < s; i++) {
            all *= k;
            k -= 1;
        }
        mint tot = 0;
        for (int i = 0; i <= s; i++) {
            tot += stir[i]*G[i];
            // cout << stir[i].val() << " " << G[i].val() << endl;
        }
        return all-tot;
    };
    cout << (good(N)-good(N-1)*(mint{2}.pow(B)-N+1)).val() << "\n";
    return 0;
}