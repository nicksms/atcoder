/**
 *      Author:  nicksms
 *      Created: 01.31.2023 16:01:52
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int t = 0;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        t += (s == "For" ? 1 : 0);
    }
    cout << (t > (N/2) ? "Yes" : "No") << "\n";
    return 0;
}