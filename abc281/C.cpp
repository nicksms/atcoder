/**
 *      Author:  nicksms
 *      Created: 01.09.2023 10:23:00
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tot = 0;
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (auto &&p : a) {
        cin >> p;
        tot += p;
    }
    t %= tot;
    for (int i = 0; i < n; i++) {
        if (t > a[i]) {
            t -= a[i];
        } else {
            cout << i+1 << " " << t << "\n";
            break;
        }
    }
    return 0;
}