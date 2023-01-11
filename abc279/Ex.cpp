/**
 *      Author:  nicksms
 *      Created: 01.11.2023 10:02:39
**/

#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
#define ll long long
const ll p = 200003;
using mint = atcoder::static_modint<p>;
mint fac[p];
mint faci[p];
ll pp[1000001];
ll pn[1000001];

mint bsmall(ll N, ll K) {
    if (K < 0 || K > N) return 0;
    else return fac[N]*faci[K]*faci[N-K];
}

mint binom(ll N, ll K) {
    ll n0 = N%p;
    ll n1 = (N/p)%p;
    ll n2 = N/(p*p);
    ll k0 = K%p;
    ll k1 = (K/p)%p;
    ll k2 = K/(p*p);
    return bsmall(n0,k0)*bsmall(n1,k1)*bsmall(n2,k2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = faci[0] = 1;
    for (int i = 1; i < 200003; i++) {
        fac[i] = i * fac[i-1];
        faci[i] = faci[i-1]/i;
    }
    for (ll k = 0; k <= 1000000; k++) {
        pp[k] = (k*(3*k+1))/2;
        pn[k] = (k*(3*k-1))/2;
    } 
    ll N, M; cin >> N >> M;
    mint tot = 0;
    ll sgn = 1;
    for (ll k = 0; pn[k] <= M-N; k++, (sgn *= -1)) {
        tot += binom(N+M-pn[k]-1, 2*N-1)*sgn;
    }
    sgn = -1;
    for (ll k = 1; pp[k] <= M-N; k++, (sgn *= -1)) {
        tot += binom(N+M-pp[k]-1, 2*N-1)*sgn;
    }
    cout << tot.val() << "\n";
}