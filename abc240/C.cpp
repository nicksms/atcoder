/**
 *      Author:  nicksms
 *      Created: 01.06.2023 20:04:19
**/

#include <bits/stdc++.h>
using namespace std;
bool dp[10001][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j-a[i] >= 0) dp[j][i] |= dp[j-a[i]][i-1];
            if (j-b[i] >= 0) dp[j][i] |= dp[j-b[i]][i-1];
        }
    }
    cout << (dp[x][n] ? "Yes" : "No") << endl;
    return 0;
}