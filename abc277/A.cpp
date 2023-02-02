/**
 *      Author:  nicksms
 *      Created: 02.02.2023 12:40:05
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, X; cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        int c; cin >> c;
        if (c == X) {cout << i << "\n"; return 0;}
    }

    return 0;
}