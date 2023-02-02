/**
 *      Author:  nicksms
 *      Created: 01.12.2023 10:33:59
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    set<pair<int,int>> s;
    while (Q--) {
        int T, A, B; cin >> T >> A >> B;
        if (T == 1) {
            s.emplace(A,B);
        } else if (T == 2) {
            s.erase(pair<int,int>{A,B});
        } else {
            cout << ((s.count(pair<int,int>{A,B})) && (s.count(pair<int,int>{B,A})) ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}