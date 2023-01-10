/**
 *      Author:  nicksms
 *      Created: 01.10.2023 06:10:19
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int tot = 0;
    for (char i : s) {
        tot += i == 'v' ? 1 : 2;
    }
    cout << tot << "\n";
    return 0;
}