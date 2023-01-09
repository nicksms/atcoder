/**
 *      Author:  nicksms
 *      Created: 01.07.2023 06:30:45
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        for (ll i = 2; i < n; i++) {
            if (n % i == 0) {
                if (n % (i*i) == 0) {
                    cout << i << " " << n/(i*i) << "\n";
                    break;
                } else {
                    ll p2 = n/i;
                    ll cand = (long long)sqrt(p2);
                    ll p = max(2ll, cand-100);
                    for (; p*p < p2; p++);
                    cout << p << " " << i << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}