/**
 *      Author:  nicksms
 *      Created: 01.15.2023 07:11:52
**/

#include <bits/stdc++.h>
#include <atcoder/dsu>
using dsu = atcoder::dsu;
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    map<string,int> dc;
    vector<string> S(N+1);
    vector<string> T(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> S[i] >> T[i];
        dc[S[i]] = 2*i;
        dc[T[i]] = 2*i+1;
    }
    dsu d(2*N+2);
    for (int i = 1; i <= N; i++) {
        if (S[i] == T[i]) {
            continue; 
        } else if (d.same(dc[S[i]], dc[T[i]])) {
            cout << "No\n";
            return 0;
        }
        d.merge(dc[S[i]], dc[T[i]]);
    }
    cout << "Yes\n";
    return 0;
}