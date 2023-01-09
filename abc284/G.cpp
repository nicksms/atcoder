/**
 *      Author:  nicksms
 *      Created: 01.07.2023 06:31:12
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nfacover[500000];
ll mpow[500000];
ll cterm[500000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    nfacover[n] = 1;
    mpow[0] = 1;
    cterm[0] = 0;
    for (ll k = 1; k <= n; k++) {
        nfacover[n-k] = (nfacover[n-k+1]*(n-k+1))%m;
        mpow[k] = (mpow[k-1]*n)%m;
    }
    cterm[1] = nfacover[0];
    for (ll k = 2; k < n; k++) {
        cterm[k] = (nfacover[k-1]*mpow[k-1])%m;
        cterm[k] = (cterm[k]+cterm[k-1])%m;
    }
    ll tot = 0;
    for (ll k = 1; k <= n-1; k++) {
        ll part = 1;
        part = (part*(n-k))%m;
        part = (part*cterm[k])%m;
        tot = (tot+part)%m;
    }
    cout << tot << endl;
    return 0;
}