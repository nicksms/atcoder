/**
 *      Author:  nicksms
 *      Created: 01.12.2023 10:42:10
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<ll,ll>> A(N+1);
    for (int i = 1; i <= N; i++) {
        ll x; cin >> x;
        A[i] = {x, 0};
    }
    pair<ll,ll> ow = {0,-1};
    int Q; cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int q; cin >> q;
        if (q == 1) {
            ll x; cin >> x; ow = {x, i};
        } else if (q == 2) {
            int j; cin >> j; ll x; cin >> x;
            if (A[j].second > ow.second) A[j].first += x;
            else A[j] = {x, i};
        } else {
            int j; cin >> j;
            cout << ow.first + (ow.second < A[j].second ? A[j].first : 0) << "\n";
        }
    }
    return 0;
}