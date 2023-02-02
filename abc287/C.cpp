/**
 *      Author:  nicksms
 *      Created: 01.31.2023 15:47:15
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <atcoder/dsu>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    if (M != N-1) {cout << "No\n"; return 0;}
    vector<int> degs(N);
    atcoder::dsu d(N+1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        if (d.same(a,b)) {cout << "No\n"; return 0;}
        d.merge(a,b);
        degs[a-1]++;
        degs[b-1]++;
    }
    sort(degs.begin(), degs.end());
    bool ans = (degs[0] == 1);
    ans &= (degs[1] == 1);
    if (degs.size() > 2) ans &= (degs[2] == 2);
    ans &= (degs[degs.size()-1] < 3);
    cout << (ans ? "Yes" : "No") << "\n";

    return 0;
}