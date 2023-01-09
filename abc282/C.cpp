/**
 *      Author:  nicksms
 *      Created: 01.05.2023 11:51:30
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    int sgn = 0;
    for (char &i : s) {
        switch (i) {
            case '"': sgn++; break;
            case ',': i = sgn % 2 == 0 ? '.' : ','; break;
            default: break;
        }
    }
    cout << s;
    return 0;
}