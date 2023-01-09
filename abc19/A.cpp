/**
 *      Author:  nicksms
 *      Created: 01.08.2023 14:53:18
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(3);
    for (auto &&p : v) cin >> p;
    sort(v.begin(), v.end());
    cout << v[1] << endl;
    return 0;
}