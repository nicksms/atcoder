/**
 *      Author:  nicksms
 *      Created: 02.02.2023 12:16:53
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct K {
    int r, l;
    ll t;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<int> A(N+1);
    ll tot = 0;
    for (int i = 1; i <= N; i++) {cin >> A[i]; tot += A[i];}
    sort(A.begin(), A.end());
    deque<K> s;
    for (int i = 1; i <= N; i++) {
        if (s.size() == 0 || s.back().r+s.back().l < A[i]) {
            s.push_back(K{A[i], 1, (ll)A[i]});
        } else {
            s.back().t += A[i];
            s.back().l = max(s.back().l, A[i]-s.back().r + 1);
        }
    }
    if (s.size() > 1 && s.front().r == 0 && s.back().r + s.back().l == M) {
        s.front().t += s.back().t;
        s.pop_back();
    }
    ll t = 0;
    for (K k : s) t = max(t, k.t);
    cout << tot-t << "\n";
    return 0;
}