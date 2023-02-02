/**
 *      Author:  nicksms
 *      Created: 01.31.2023 12:57:42
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool dp1[300001];
bool dp2[300001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp1[0] = dp2[0] = true;
    string S, T; cin >> S >> T;
    for (int i = 1; i <= 300000; i++) {
        if (i <= S.size() && i <= T.size() && (S[i-1] == '?' || T[i-1] == '?' || S[i-1] == T[i-1])) dp1[i] |= dp1[i-1];
        if (i <= S.size() && i <= T.size() && (S[S.size()-i] == '?' || T[T.size()-i] == '?' || S[S.size()-i] == T[T.size()-i])) dp2[i] |= dp2[i-1];
    }
    for (int i = 0; i <= T.size(); i++) cout << ((dp1[i] && dp2[T.size()-i]) ? "Yes" : "No") << "\n";
    
    return 0;
}