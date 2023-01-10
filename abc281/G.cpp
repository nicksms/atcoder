/**
 *      Author:  nicksms
 *      Created: 01.09.2023 14:46:17
**/

#include <bits/stdc++.h>
#include <atcoder/modint>
using mint = atcoder::modint;
using namespace std;
#define ll long long
mint dp[501][501]; // totused, lastused
mint C[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    mint::set_mod(M);
    dp[1][1] = mint{1};
    for (int i = 0; i <= 500; i++) {
        C[i][0] = C[i][i] = mint{1};
        for (int j = 1; j <= i-1; j++) C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    for (int tu = 2; tu <= N-1; tu++) 
        for (ll un = 1; un <= tu; un++) 
            for (int ul = 1; ul <= tu-un; ul++) 
                dp[tu][un] += dp[tu-un][ul]*(mint{2}.pow((un*un-un)/2))*((mint{2}.pow(ul)-mint{1}).pow(un))*C[N-1+(un-tu)][un];
    mint ans(0);
    for (int i = 1; i <= N-2; i++) ans += dp[N-1][i]*(mint{2}.pow(i)-mint{1});
    cout << ans.val() << "\n";
    return 0;
}