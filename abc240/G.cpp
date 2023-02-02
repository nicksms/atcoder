/**
 *      Author:  nicksms
 *      Created: 01.20.2023 22:42:39
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 10000000;
#include <atcoder/modint>
using mint = atcoder::modint998244353;
mint fac[maxN+1];
mint faci[maxN+1];

mint C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n]*faci[n-k]*faci[k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, X, Y, Z; cin >> N >> X >> Y >> Z;
    fac[0] = faci[0] = 1;
    for (int i = 1; i <= maxN; i++) fac[i]=i*fac[i-1];
    faci[maxN] = 1/fac[maxN];
    for (int i = maxN-1; i >= 1; i--) faci[i]=(i+1)*faci[i+1];
    int s = abs(X+Y);
    int d = abs(X-Y);
    int z = abs(Z);
    mint tot = 0;
    for (int k = 0; k <= N; k++) {
        if ((k+s)%2==0 && (k+d)%2==0 && (N-k+z)%2==0) tot += C(k, (s+k)/2)*C(k, (d+k)/2)*C(N-k, (N-k+z)/2)*C(N,k);
    }
    cout << tot.val() << "\n";
    return 0;
}