/**
 *      Author:  nicksms
 *      Created: 01.10.2023 08:40:28
**/

#include <bits/stdc++.h>
#include <atcoder/dsu>
using dsu = atcoder::dsu;
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    vector<int> reps(N+1);
    vector<int> which(N+Q+1);
    for (int i = 1; i < N+Q+1; i++) {
        if (i <= N) reps[i] = i;
        which[i] = i;
    }
    dsu d(N+Q+1);
    int k = N;
    for(int i = 0; i < Q; i++) {
        int c; cin >> c;
        if (c == 1) {
            int X, Y; cin >> X >> Y;
            if (reps[X] == 0) {
                reps[X] = reps[Y];
            }
            else if (reps[Y] != 0) {
                d.merge(reps[X],reps[Y]);
                which[d.leader(reps[X])] = X;
            }
            if (reps[Y] != 0) which[d.leader(reps[Y])] = X;
            reps[Y] = 0;
        } else if (c == 2) {
            int X; cin >> X;
            ++k;
            if (reps[X] == 0) {
                reps[X] = k;
                which[k] = X;
            } else {
                d.merge(reps[X], k);
                which[d.leader(reps[X])] = X;
            }
        } else {
            int X; cin >> X;
            cout << which[d.leader(X)] << endl;
        }
    }
    return 0;
}