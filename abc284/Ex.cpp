/**
 *      Author:  nicksms
 *      Created: 01.07.2023 06:31:20
 *      > "oh it's just burnside's"
 *      > brick
 *      > look at the editorial
 *      > it's just burnside's
**/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using mint = atcoder::modint;
#define ll long long
mint fac[31];

mint A(int n, int k) {
    vector<pair<int, int>> v; // size, mult.
    mint ans{0};
    auto eparts = [&](int N, int last, auto &&eparts) -> void {
        if (N == 0) {
            mint cans = 1;
            for (int i = 0; i < v.size(); i++) {
                cans *= mint{k}.pow(v[i].second);
                cans *= mint{2}.pow((v[i].first/2)*v[i].second);
                cans /= fac[v[i].second]*mint{v[i].first}.pow(v[i].second); // implicit mult, div by N! -- cycles permute and themselves rotate
                for (int j = 0; j < i; j++) {
                    cans *= mint{2}.pow(gcd(v[i].first, v[j].first)*v[i].second*v[j].second);
                }
                int c2 = (v[i].second*(v[i].second-1))/2;
                cans *= mint{2}.pow(v[i].first*c2);
            }
            ans += cans;
            return;
        }
        for (int j = last + 1; j <= N; j++) {
            for (int i = 1; i*j <= N; i++) {
                v.emplace_back(j,i);
                eparts(N-j*i, j, eparts);
                v.pop_back();
            }
        }
        return;
    };
    eparts(n,0,eparts);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, p;
    cin >> n >> k >> p;
    mint::set_mod(p);
    fac[0] = 1;
    for (int i = 1; i <= 30; i++) {
        fac[i] = fac[i-1]*mint{i};
    }
    mint tot(0);
    mint n1(k % 2 ? -1 : 1);
    for (int i = 1; i <= k; i++) {
        n1 *= mint{-1};
        tot += fac[k]/fac[i]/fac[k-i] * n1 * A(n,i);
    }
    cout << tot.val() << "\n";
    return 0;
}