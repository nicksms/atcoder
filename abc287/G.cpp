/**
 *      Author:  nicksms
 *      Created: 01.30.2023 17:15:12
**/

#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
#define ll long long
using pii = pair<ll, ll>;
pii e() {return pii{0,0};}
pii op(pii a, pii b) {return pii{a.first+b.first, a.second+b.second};}
using st = atcoder::segtree<pii, op, e>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    set<ll> ap;
    for (int i = 0; i < N; i++) { cin >> a[i] >> b[i]; ap.insert(a[i]);}
    int Q; cin >> Q;
    vector<vector<ll>> qs(Q);
    for (int i = 0; i < Q; i++) {
        int c; cin >> c;
        if (c == 3) {
            qs[i].resize(2);
            qs[i][0] = c;
            cin >> qs[i][1];
        } else {
            qs[i].resize(3);
            qs[i][0] = c;
            cin >> qs[i][1] >> qs[i][2];
            if (c == 1) ap.insert(qs[i][2]);
        }
    }
    vector<ll> ks;
    for (ll k : ap) ks.push_back(k);
    sort(ks.begin(), ks.end());
    map<ll, int> rev;
    for (int i = 0; i < ks.size(); i++) rev[ks[i]] = i;
    st sg(ks.size());
    for (int i = 0; i < N; i++) {
        int ind = rev[a[i]];
        pii x = sg.get(ind);
        x.first += b[i]*((ll)a[i]);
        x.second += b[i];
        sg.set(ind, x);
    }
    for (int i = 0; i < Q; i++) {
        int c = qs[i][0];
        if (c == 1) {
            ll x = qs[i][1], y = qs[i][2];
            x -= 1;
            int ind = rev[a[x]];
            pii p = sg.get(ind);
            p.first -= (a[x]*((ll)b[x]));
            p.second -= b[x];
            sg.set(ind, p);
            a[x] = y;
            ind = rev[a[x]];
            p = sg.get(ind);
            p.first += (a[x]*((ll)b[x]));
            p.second += b[x];
            sg.set(ind, p);
        } else if (c == 2) {
            ll x = qs[i][1], y = qs[i][2];
            x -= 1;
            int ind = rev[a[x]];
            pii p = sg.get(ind);
            p.first -= (a[x]*((ll)b[x]));
            p.second -= b[x];
            sg.set(ind, p);
            b[x] = y;
            ind = rev[a[x]];
            p = sg.get(ind);
            p.first += (a[x]*((ll)b[x]));
            p.second += b[x];
            sg.set(ind, p);
        } else {
            ll x = qs[i][1];
            pii tot = sg.all_prod();
            if (tot.second < x) {
                cout << "-1\n";
                continue;
            }
            int r = sg.max_right(0, [&] (pii xx) -> bool {
                return xx.second <= tot.second - x;
            });
            pii anti = sg.prod(0,r);
            tot.first -= anti.first;
            tot.second -= anti.second;
            if (r < ks.size()) tot.first -= ks[r]*(tot.second-x);
            cout << tot.first << "\n";
        }
    }
    return 0;
}