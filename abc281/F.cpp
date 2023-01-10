/**
 *      Author:  nicksms
 *      Created: 01.09.2023 13:41:39
**/

#include <bits/stdc++.h>
using namespace std;
int ans(int b, const vector<int>& v) {
    if (v.size() == 0 || b == -1) return 0;
    vector<int> l, r;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] & 1<<b) {
            r.push_back(v[i]);
        } else {
            l.push_back(v[i]);
        }
    }
    if (l.size() == 0) return ans(b-1, r);
    if (r.size() == 0) return ans(b-1, l);
    return (1<<b) + min(ans(b-1, l), ans(b-1, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (auto &&p : v) cin >> p;
    cout << ans(31, v) << "\n";
    return 0;
}