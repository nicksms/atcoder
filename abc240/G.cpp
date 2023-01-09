/**
 *      Author:  nicksms
 *      Created: 01.07.2023 19:27:17
 *
 *      DOES NOT WORK
**/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using mint = atcoder::static_modint<998244353>;
#define ll long long
mint fac[10000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    X = abs(X); Y = abs(Y); Z = abs(Z);
    // mint N(Nl); mint X(Xl); mint Y(Yl); mint Z(Zl);
    fac[0] = 1;
    for (mint i(1); i.val() <= N; i++) {
        fac[i.val()]=fac[i.val()-1]*i;
    }
    ll Np = N-X-Y-Z;
    if (Np < 0 || Np %2 != 0) {
        cout << 0;
        return 0;
    }
    Np /= 2;
    mint tot(0);
    for (ll tx = 0; tx <= Np; tx++) {
        mint num = fac[N]*fac[N-2*tx-X];
        mint denom = fac[tx]*fac[Np-tx]*fac[Np-tx]*fac[tx+X]*fac[N-Np-tx-X]*fac[N-Np-tx-X];
        tot += num/denom;
    }
    cout << tot.val() << "\n";
    return 0;
}