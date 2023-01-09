/**
 *      Author:  nicksms
 *      Created: 01.06.2023 19:59:43
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b; cin >> a >> b;
    cout << (abs(a-b) == 1 || abs(a-b) == 9 ? "Yes" : "No") << endl;
    return 0;
}