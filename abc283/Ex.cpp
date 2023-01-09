/**
 *      Author:  nicksms
 *      Created: 01.08.2023 11:30:26
**/

#include <bits/stdc++.h>
#include <atcoder/math>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll n, m, r;
        cin >> n >> m >> r;
        ll tot = 0;
        for (int k = 0; k <= 30; k++) {
            tot += atcoder::floor_sum((n-r)/m + 1, 1ll<<(k+1), m, r + (1ll<<(k))) - atcoder::floor_sum((n-r)/m + 1, 1ll<<(k+1), m, r);
        }
        cout << tot << "\n";
    }
    return 0;
}