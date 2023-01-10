/**
 *      Author:  nicksms
 *      Created: 01.10.2023 06:23:22
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W; cin >> H >> W;
    vector<string> m1(H);
    vector<string> m2(H);
    multiset<string> s1,s2;
    for (int i = 0; i < H; i++) cin >> m1[i];
    for (int i = 0; i < H; i++) cin >> m2[i];
    for (int i = 0; i < W; i++) {
        string ss1, ss2;
        for (int j = 0; j < H; j++) {
            ss1.push_back(m1[j][i]);
            ss2.push_back(m2[j][i]);
        }
        s1.insert(ss1);
        s2.insert(ss2);
    }
    cout << (s1 == s2 ? "Yes" : "No") << "\n";
    return 0;
}