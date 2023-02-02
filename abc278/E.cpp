/**
 *      Author:  nicksms
 *      Created: 01.12.2023 10:56:15
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[301][301][301];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W, N, h, w; cin >> H >> W >> N >> h >> w;
    vector<vector<int>> A(H+1, vector<int>(W+1));
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) {
            cin >> A[i][j];
            for (int k = 1; k <= N; k++) {
                dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
            }
            dp[i][j][A[i][j]] += 1;
        }
    
    for (int k = 0; k <= H-h; k++) {
        for (int j = 0; j <= W-w; j++) {
            int tot = 0;
            for (int i = 1; i <= N; i++) {
                if (dp[H][W][i] != dp[k+h][j+w][i] - dp[k][j+w][i]-dp[k+h][j][i]+dp[k][j][i]) tot++;
            }
            cout << tot << " ";
        }
        cout << "\n";
    }

    return 0;
}