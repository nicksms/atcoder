/**
 *      Author:  nicksms
 *      Created: 01.06.2023 09:36:29
**/

#include <bits/stdc++.h>
using namespace std;
inline int lg(int n) {
    return 31-__builtin_clz(n);
}

int ids[4001][12];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << n*12 << endl;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 12; j++) {
            ids[i][j] = cnt++;
            //cout << cnt-1 << " ";
            cout << i << " " << min(n, i+(1<<j)-1) << endl;
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int al = 1<<lg(r-l+1);
        if (r-l+1 == al) {
            cout << ids[l][lg(r-l+1)] << " " << ids[l][lg(r-l+1)] << endl;
        } else {
            int lo = r-l+1-al;
            int bl = 1<<lg(lo);
            if (bl != lo) bl <<= 1;
            cout << ids[l][lg(al)] << " " << ids[r-bl+1][lg(bl)] << endl;
        }
    }
    return 0;
}