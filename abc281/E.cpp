/**
 *      Author:  nicksms
 *      Created: 01.09.2023 11:10:27
**/

#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
#define ll long long

using S = pair<ll, int>;
S op(S a, S b) { return S{a.first+b.first, a.second+b.second}; }
S e() { return S{0,0}; }
using sg = atcoder::segtree<S,op,e>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K; cin >> N >> M >> K;
    vector<ll> A(N);
    vector<S> inds(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        inds[i] = S{A[i],i};
    }
    sort(inds.begin(), inds.end());
    vector<int> si(N);
    for (int i = 0; i < N; i++) si[inds[i].second] = i;
    sg st(N+2);
    for (int i = 0; i < M; i++) st.set(si[i]+1,S{A[i],1});
    auto f = [&](S x) -> bool { return x.second < K; };
    cout << st.prod(0, st.max_right(0,f)+1).first << " ";
    for (int i = 1; i <= N-M; i++) {
        st.set(si[i-1]+1,e());
        st.set(si[i+M-1]+1,S(A[i+M-1],1));
        cout << st.prod(0, st.max_right(0,f)+1).first << " ";
    }
    cout << "\n";    
    return 0;
}