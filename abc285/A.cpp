/**
 *      Author:  nicksms
 *      Created: 01.15.2023 07:00:37
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b; cin >> a >> b;
    cout << ((b == 2*a || b == 2*a + 1) ? "Yes" : "No") << "\n";
    return 0;
}