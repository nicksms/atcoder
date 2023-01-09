/**
 *      Author:  nicksms
 *      Created: 01.05.2023 10:26:02
 *      Mostly copied from editorial.
**/

#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
int op(int a, int b) {return max(a,b);}
int e() {return -100000000;}
using st = atcoder::segtree<int, op, e>;

void calc(int N, const vector<int> &P, vector<int> &D) {
    st s(N);
    for (int i = 0; i < N; i++) {
        D[i] = min(D[i], P[i] + i - s.prod(0, P[i]));
        s.set(P[i]-1, P[i]+i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> P(N); for (auto &&p : P) cin >> p;
    vector<int> D(N); for (auto &&d : D) d = 5*N;

    calc(N, P, D); // case 4
    for (auto &&p : P) p = N + 1 - p;
    calc(N, P, D); // case 2
    reverse(P.begin(), P.end()); reverse(D.begin(), D.end());
    calc(N, P, D); // case 3 (process j > i before i, include P[j] > P[i]) in the query
    for (auto &&p : P) p = N + 1 - p;
    calc(N, P, D); // case 1 (process j > i before i, include P[j] < P[i]) in the query

    reverse(D.begin(), D.end());
    for (auto &&d : D) cout << d << " ";
    cout << endl;

    return 0;
}