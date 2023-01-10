/**
 *      Author:  nicksms
 *      Created: 01.10.2023 06:36:53
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ld calc(ld C, ll k) {
    return C*k + 1/sqrt(1+k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll A, B; cin >> A >> B;
    cout << fixed << setprecision(numeric_limits<ld>::digits10 + 1);
    ld C = B/(ld)A;
    ld best = calc(C,0);
    ld h3 = 1/(2*C);
    ld hguess = cbrt(h3);
    ld kguess = max(0.0l, hguess*hguess-1);
    for (ll k = max((ll)kguess-100,0ll); k <= max((ll)kguess+100, 0ll); k++) best = min(best, calc(C,k));
    cout << fixed << setprecision(numeric_limits<ld>::digits10 + 1) << A*best << "\n";
    
    return 0;
}