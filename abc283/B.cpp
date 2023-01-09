/**
 *      Author:  nicksms
 *      Created: 01.07.2023 21:41:57
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (auto &&p : v) cin >> p;
    int q; cin >> q;
    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int k, x; cin >> k >> x;
            v[k-1] = x;
        } else {
            int k; cin >> k;
            cout << v[k-1] << "\n";
        }
    }

    return 0;
}