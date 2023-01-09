/**
 *      Author:  nicksms
 *      Created: 01.07.2023 06:30:29
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x % 2 == 1) {
                tot += 1;
            }
        }
        cout << tot << "\n";
    }
    return 0;
}