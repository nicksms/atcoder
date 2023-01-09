/**
 *      Author:  nicksms
 *      Created: 01.08.2023 10:10:59
**/

#include <bits/stdc++.h>
using namespace std;
using bs = bitset<64>;
using ll = unsigned long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    ll l, r;
    cin >> l >> r;
    l--, r--;
    vector<ll> pivots(65);
    auto update_pivots = [&](ll v) -> void {
        for (int i = 0; i < pivots.size(); i++) {
            if (v & (i > 0 ? 1ull<<(i-1) : 0)) {
                v ^= pivots[i];
            }
        }
        ll leading = __builtin_clzll(v) > 0 ? (1ull<<(63-__builtin_clzll(v))) : 0;
        for (int i = 0; i < pivots.size(); i++) {
            if (pivots[i] & leading) {
                pivots[i] ^= v;
            }
        }
        pivots[64-__builtin_clzll(v)] = v;
    };
    while (n--) {
        ll v; cin >> v;
        update_pivots(v);
    }
    vector<ll> nzp;
    for (ll p : pivots) {
        if (p != 0) {
            nzp.push_back(p);
        }
    }
    if (nzp.size() == 0) nzp.push_back(0);
    for (ll i = l; i <= r; i++) {
        bs b(i);
        ll tot = 0;
        for (int j = 0; j < nzp.size(); j++) {
            if (b[j]) {
                tot ^= nzp[j];
            }
        }
        cout << tot << " ";
    }
    cout << "\n";

    return 0;
}