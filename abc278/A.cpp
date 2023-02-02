/**
 *      Author:  nicksms
 *      Created: 01.12.2023 10:09:41
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = K+1; i <= N; i++) cout << A[i] << " ";
    for (int i = 0; i < N-max(N-K, 0); i++) cout << 0 << " ";
    cout << "\n";
    return 0;
}