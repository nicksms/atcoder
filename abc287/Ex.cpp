/**
 *      Author:  nicksms
 *      Created: 01.30.2023 16:54:21
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using bs = bitset<2000>;
bs ins[2000];
bs outs[2000];
bs ansin[2000];
bs ansout[2000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<vector<int>> in(N);
    vector<vector<int>> out(N);
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        in[b].push_back(a);
        out[a].push_back(b);
    }
    for (int i = 0; i < N; i++) {
        ansin[i][i] = 1;
        ansout[i][i] = 1;
        for (int v : in[i]) ansin[i] |= ins[v];
        for (int v : out[i]) ansout[i] |= outs[v];
        for (int j = 0; j <= i; j++) {
            if (ansin[i][j]) outs[j] |= ansout[i];
            if (ansout[i][j]) ins[j] |= ansin[i];
        }
    }
    auto query = [&](int a, int b) -> int {
        for (int i = 0; i < N; i++) {
            if (ansin[i][a] && ansout[i][b]) return i+1;
        }
        return -1;
    };
    int Q; cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        a--, b--;
        cout << query(a,b) << "\n";
    }

    return 0;
}