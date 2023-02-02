/**
 *      Author:  nicksms
 *      Created: 01.14.2023 08:17:29
 *      DOES NOT WORK. Incorrect greedy.
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ds(ll n){return n == 0 ? 0 : n%10 + ds(n/10);}
ll nc(ll a,ll b){return (ds(a) + ds(b) - ds(a+b)) / 9;}


ll besth(vector<int> &ans, bool o) {
    bool b = true;
    for (int i : ans) {
        if ((i > 1) || (i > 0 && o)) b = false;
    }
    if (b) return 0;
    int besti = 0;
    ll bestv = 0;
    for (int i = 1; i <= 9; i++) {
        ll v = 0;
        for (int j = 0; j < ans.size(); j++) {
            v += nc(ans[j], i);
        }
        v = 9*v - ans.size()*i;
        // cout << ans[1] << " " << i << v << endl;
        if (v >= bestv || (i == 1 && o)) {
            bestv = v;
            besti = i;
            // cout << i << ans[1];
        }
    }
    for (int j = 0; j < ans.size(); j++) {
        ans[j] = (ans[j]+besti)/10;
    }
    return bestv + besth(ans, false);
}

ll best(vector<int> ans) {
    vector<int> na = ans;
    ll bestt = besth(na, true);
    while (true) {
        for (int i = 0; i < ans.size(); i++) {
            ans[i] /= 10;
        }
        bool b = true;
        for (int i : ans) {if (i) b = false;}
        if (b) return bestt;
        na = ans;
        bestt = max(bestt, besth(na, true));
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N; cin >> N;
    vector<int> A(N);
    ll tot = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        tot += ds(A[i]);
    }
    cout << tot - max(best(A), 0ll) << "\n";
    return 0;
}