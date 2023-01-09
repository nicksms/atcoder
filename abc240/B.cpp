/**
 *      Author:  nicksms
 *      Created: 01.06.2023 20:02:06
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> s;
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        s.insert(t);
    }
    cout << s.size() << endl;
    return 0;
}