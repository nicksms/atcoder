/**
 *      Author:  nicksms
 *      Created: 01.09.2023 10:29:06
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[102][102][102];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, D;
    cin >> N >> K >> D;
    vector<ll> a(N+1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int m = 0; m < D; m++) {
                if (j == 0 && m == 0) {
                    dp[j][i][m] = 0;
                } else dp[j][i][m] = -1;
            }
        }
    }
    for (int k = 1; k <= K; k++) {
        for (int n = 1; n <= N; n++) {
            for (int m = 0; m < D; m++) {
                dp[k][n][m] = max(dp[k][n][m], dp[k][n-1][m]);
                if (dp[k-1][n-1][(((m-a[n])%D)+D)%D] != -1) dp[k][n][m] = max(dp[k][n][m], a[n] + dp[k-1][n-1][(((m-a[n])%D)+D)%D]);
            }
        }
    }
    cout << dp[K][N][0] << "\n";
    return 0;
}