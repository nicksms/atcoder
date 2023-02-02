/**
 *      Author:  nicksms
 *      Created: 01.14.2023 07:01:44
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int d1 = 1, d3 = 0, d4=0, d6=0, d7 = 0, d8=0;
    int N; cin >> N;
    N-=1;
    while (N--) {
        d8 += 1;
        d7 += d8/10;
        d8 %= 10;
        d6 += d7/10;
        d7 %= 10;
        d4 += d6/10;
        d6 %= 10;
        d3 += d4/10;
        d4 %= 10;
        d1 += d3/10;
        d3 %= 10;
    }
    cout << d1 << d1 << d3 << d4 << d6 << d6 << d7 << d8 << d7 << "\n";

    return 0;
}