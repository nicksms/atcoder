/**
 *      Author:  nicksms
 *      Created: 01.05.2023 11:15:50
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; cin >> k;
    string s = "QWERTYUIOPASDFGHJKLZXCVBNM"; sort(s.begin(), s.end());
    cout << s.substr(0, k);
    return 0;
}