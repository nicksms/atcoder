/**
 *      Author:  nicksms
 *      Created: 01.09.2023 10:15:27
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int tot = 0;
    for (int i = 0; i < (s.size() == 8 ? 9 : 0); i++) {
        if (i == 0 || i == 7) {
            tot += (s[i] >= 'A' && s[i] <= 'Z') ? 1 : 0;
        } else if (i == 1) {
            tot += (s[i] >= '1' && s[i] <= '9') ? 1 : 0;
        } else if (i == 8) {
            tot += (s.size() == 8) ? 1 : 0;
        } else {
            tot += (s[i] >= '0' && s[i] <= '9') ? 1 : 0;
        }
    }
    cout << (tot == 9 ? "Yes\n" : "No\n");
    return 0;
}