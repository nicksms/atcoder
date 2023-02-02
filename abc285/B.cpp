/**
 *      Author:  nicksms
 *      Created: 01.15.2023 07:03:32
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    string S; cin >> S;
    for (int i = 0; i < N-1; i++) {
        int best = 0;
        for (int j = 1; j + i < N; j++) {
            if (S[j-1] == S[i+j]) break;
            best = j;
        }
        cout << best << " ";
    }
    cout << "\n";
    return 0;
}