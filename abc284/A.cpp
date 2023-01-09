/**
 *      Author:  nicksms
 *      Created: 01.07.2023 06:30:20
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> s(n);
    for (auto &&p : s) cin >> p;
    reverse(s.begin(), s.end());
    for (auto &&p : s) cout << p << "\n";
    return 0;
}