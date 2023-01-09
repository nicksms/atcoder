/**
 *      Author:  nicksms
 *      Created: 01.06.2023 10:09:46
**/

#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101][101];
int rss[101][101][101]; // third param is a
int css[101][101][101]; // third param is b

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, p;
    cin >> N >> K >> p;
    dp[2][0][1][1] = 0;
    dp[2][0][1][2] = 1;
    dp[2][0][2][1] = 1;
    dp[2][0][2][2] = 0;
    dp[2][1][1][1] = 1;
    dp[2][1][1][2] = 0;
    dp[2][1][2][1] = 0;
    dp[2][1][2][2] = 1;
    rss[2][0][1] = rss[2][0][2] = rss[2][1][1] = rss[2][1][2] 
    = css[2][0][1] = css[2][0][2] = css[2][1][1] = css[2][1][2] = 1;
    for (int n = 3; n <= N; n++) {
        for (int k = 0; k < n; k++) {
            dp[n][k][1][1] = 0;
            if (k > 0)
            for (int a = 1; a < n; a++) {
                dp[n][k][1][1] += rss[n-1][k-1][a];
                if (dp[n][k][1][1] >= p) {
                    dp[n][k][1][1] -= p;
                }
            }
            rss[n][k][1] = css[n][k][1] = dp[n][k][1][1];
            for (int a = 2; a <= n; a++) {
                dp[n][k][a][1] = dp[n][k][a-1][1];
                if (k > 0) {
                    dp[n][k][a][1] -= rss[n-1][k-1][a-1];
                    if (dp[n][k][a][1] < 0) dp[n][k][a][1] += p;
                }
                if (k < n-1) {
                    dp[n][k][a][1] += rss[n-1][k][a-1];
                    if (dp[n][k][a][1] >= p) dp[n][k][a][1] -= p;
                }
                rss[n][k][a] += dp[n][k][a][1];
                if (rss[n][k][a] >= p) rss[n][k][a] -= p;
                css[n][k][1] += dp[n][k][a][1];
                if (css[n][k][1] >= p) css[n][k][1] -= p;
            }
            for (int b = 2; b <= n; b++) {
                dp[n][k][1][b] = dp[n][k][1][b-1];
                if (k > 0) {
                    dp[n][k][1][b] -= css[n-1][k-1][b-1];
                    if (dp[n][k][1][b] < 0) dp[n][k][1][b] += p;
                }
                if (k < n-1) {
                    dp[n][k][1][b] += css[n-1][k][b-1];
                    if (dp[n][k][1][b] >= p) dp[n][k][1][b] -= p;
                }
                rss[n][k][1] += dp[n][k][1][b];
                if (rss[n][k][1] >= p) rss[n][k][1] -= p;
                css[n][k][b] += dp[n][k][1][b];
                if (css[n][k][b] >= p) css[n][k][b] -= p;
            }
            for (int a = 2; a <= n; a++) {
                for (int b = 2; b <= n; b++) {
                    dp[n][k][a][b] = dp[n][k][a-1][b];
                    dp[n][k][a][b] += dp[n][k][a][b-1];
                    if (dp[n][k][a][b] >= p) dp[n][k][a][b] -= p;
                    dp[n][k][a][b] -= dp[n][k][a-1][b-1];
                    if (dp[n][k][a][b] < 0) dp[n][k][a][b] += p;
                    if (k > 0) {
                        dp[n][k][a][b] += 2*dp[n-1][k-1][a-1][b-1] % p;
                        dp[n][k][a][b] %= p;
                    }
                    if (k < n-1) {
                        dp[n][k][a][b] -= 2*dp[n-1][k][a-1][b-1] % p;
                        dp[n][k][a][b] %= p;
                        dp[n][k][a][b] += p;
                        dp[n][k][a][b] %= p;
                    }
                    rss[n][k][a] += dp[n][k][a][b];
                    if (rss[n][k][a] > p) rss[n][k][a] -= p;
                    css[n][k][b] += dp[n][k][a][b];
                    if (css[n][k][b] > p) css[n][k][b] -= p;
                }
            }
        }
    }
    int ans = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= N; b++) {
            ans += dp[N][K][a][b];
            if (ans >= p) ans -= p;
        }
    }
    cout << ans << endl;
    return 0;
}