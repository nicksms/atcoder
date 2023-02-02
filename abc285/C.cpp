/**
 *      Author:  nicksms
 *      Created: 01.15.2023 07:06:59
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S; cin >> S;
    ll tot = 0;
    ll pow = 1;
    for (int i = S.size()-1; i >= 0; i--) {
        tot += (S[i]-'A'+1)*(pow);
        pow *= 26;
    }
    cout << tot << "\n";
    return 0;
}