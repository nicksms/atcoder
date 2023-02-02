/**
 *      Author:  nicksms
 *      Created: 01.31.2023 15:55:37
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    multiset<string> m;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        m.insert(s.substr(3));
    }
    int tot = 0;
    for (int i = 0; i < M; i++) {
        string t; cin >> t;
        tot += m.erase(t);
    }
    cout << tot << "\n";

    return 0;
}