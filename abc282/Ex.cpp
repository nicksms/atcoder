/**
 *      Author:  nicksms
 *      Created: 01.06.2023 14:58:33
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <atcoder/segtree>

pair<ll, int> op(pair<ll,int> a, pair<ll,int> b) {
    if (a.first > b.first) return b;
    else return a;
}

pair<ll, int> e() {
    return pair<ll,int>{1LL<<62, -1};
}

using st = atcoder::segtree<pair<ll, int>, op, e>;
ll tot = 0;

void dnq(int L, int R, ll S, const vector<ll>& a, const vector<ll>& b, const vector<ll>& c, st& sg) {
    // cout << L << " " << R << endl;
    if (L == R) {
        if (a[L] + b[L] <= S) tot++;
        // cout << L << " to " << L << endl;
        // cout << L << " " << R << endl;
        return;
    }
    if (L > R) return;
    int M = sg.prod(L,R+1).second;
    // cout << M << endl;
    if (M-L < R-M) {
        for (int i = L; i <= M; i++) {
            ll ms = i > 0 ? -c[i-1] : 0;
            if (a[M] + c[M] + ms > S) continue;
            int l = M; int r = R+1;
            while (r-l > 1) {
                int m = (l + r)/2;
                if (a[M] + c[m] + ms <= S) {
                    l = m;
                } else {
                    r = m;
                }
            }
            // cout << i << " to " << l << endl;
            tot += l-M+1;
        }
    } else {
        for (int i = M; i <= R; i++) {
            if (M > 0) {
                if (c[i]-c[M-1]+a[M] > S) continue;
            } else if (c[i] + a[M] > S) continue;
            int l = L-1; int r = M;
            while (r-l > 1) {
                int m = (l + r)/2;
                if (a[M] + c[i] - (m > 0 ? c[m-1] : 0) <= S) {
                    r = m;
                } else {
                    l = m;
                }

            }
            // cout << r << " to " << i << endl;
            tot += M-r+1;
        }
    }
    dnq(L, M-1, S, a, b, c, sg);
    dnq(M+1, R, S, a, b, c, sg);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &&p : a) cin >> p;
    for (auto &&p : b) cin >> p;
    vector<ll> c(n);
    c[0] = b[0];
    for (int i = 1; i < n; i++) c[i] = c[i-1] + b[i];
    st sg(n); for (int i = 0; i < n; i++) sg.set(i, pair<ll, int>{a[i],i});
    dnq(0, n-1, s, a, b, c, sg);
    cout << tot << endl;
    return 0;
}