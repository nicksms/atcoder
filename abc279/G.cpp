/**
 *      Author:  nicksms
 *      Created: 01.11.2023 09:43:13
 *      Had to read the editorial for this one
 *      Had a "solution" that seemed like it would work with gfuncs and FFT but didn't test it; 
 *      checked for a mention in any of the editorials and there was only a japanese one 
 *      with a completely different gfunc so I just gave up on the idea of implementing it.
**/

#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
#define ll long long
using mint = atcoder::modint998244353;
mint dp[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, C;
    cin >> N >> K >> C;
    mint same = C;
    mint winsum = 0;
    for (int i = 2; i <= N; i++) {
        if (i-K > 0) same += dp[i-K]; // last different is now > K away
        dp[i-1] += (C-1)*same; // changing at i-1 to any color
        if (i-K > 0) winsum -= dp[i-K]; 
        dp[i-1] += winsum; // changing at i-1 to the other color that has appeared in the K before
        winsum += dp[i-1]; // update window sum
    }
    cout << (same + winsum).val() << "\n";
    return 0;
}