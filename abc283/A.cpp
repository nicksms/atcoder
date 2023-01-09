/**
 *      Author:  nicksms
 *      Created: 01.07.2023 21:38:40
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b; cin >> a >> b;
    long long ans = 1;
    while (b--) ans *= a;
    cout << ans;
    return 0;
}