/**
 *      Author:  nicksms
 *      Created: 02.02.2023 12:34:38
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    set<char> S, F;
    for (char i : "HDCS") S.insert(i);
    for (char i : "A23456789TJQK") F.insert(i);
    set<string> C;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (!S.count(s[0]) || !F.count(s[1])) {
            cout << "No\n";
            return 0;
        }
        C.insert(s);
    }
    cout << (C.size() == N ? "Yes" : "No") << "\n";
    return 0;
}