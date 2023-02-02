/**
 *      Author:  nicksms
 *      Created: 01.15.2023 07:20:01
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[5001];
ll calc(int i, int j, const vector<ll>& p) {
    int mid = (i+j)/2;
    return p[mid-i] + p[j-(mid+1)];
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<ll> A(N+1);
    vector<ll> p(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        p[i] = A[i] + p[i-1];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + calc(j,i, p));
        }
        // cout << dp[i];
    }
    cout << dp[N] << "\n";
    return 0;
}