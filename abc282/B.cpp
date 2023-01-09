/**
 *      Author:  nicksms
 *      Created: 01.05.2023 11:18:23
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<string> s(n); for(auto &&x : s) cin >> x;
    vector<bitset<31>> p; p.reserve(n); 
    transform(s.begin(), s.end(), back_inserter(p), [m](const string &st) {return bitset<31>(st.c_str(),m,'x','o');});
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((p[i] | p[j]).count() == m) tot += 1;
        }
    }
    cout << tot << endl;
    return 0;
}