/**
 *      Author:  nicksms
 *      Created: 01.07.2023 21:46:29
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S; cin >> S;
    int z = 0;
    int tot = 0;
    for (char c : S) {
        if (c > '0') {
            z = 0;
            tot += 1;
        } else if (c == '0' && z > 0) {
            z -= 1;
        } else {
            z += 1;
            tot += 1;
        }
    }
    cout << tot << endl;
    return 0;
}