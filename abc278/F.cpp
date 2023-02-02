/**
 *      Author:  nicksms
 *      Created: 01.12.2023 11:14:43
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int adj[26][26];
int sout[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    while (N--) {
        string s; cin >> s;
        adj[s[0]-'a'][s[s.size()-1]-'a'] += 1;
        sout[s[0]-'a'] += 1;
    }
    auto dfs = [&](int v, auto &&dfs) -> bool {
        if (sout[v] == 0) return true;
        for (int i = 0; i < 26; i++) {
            if (adj[v][i]) {
                adj[v][i] -= 1;
                sout[v] -= 1;
                if (dfs(i, dfs)) {
                    sout[v] += 1;
                    adj[v][i] += 1;
                    // cout << "jump " << v << " " << i << " failed\n";
                    return false;
                }
                sout[v] += 1;
                adj[v][i] += 1;
            }
        }
        return true;
    };
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (adj[i][j]) {
                adj[i][j] -= 1;
                sout[i] -= 1;
                if (dfs(j, dfs)) {
                    cout << "First\n";
                    return 0;
                }
                sout[i] += 1;
                adj[i][j] += 1;
            }
        }
    }
    cout << "Second\n";
    return 0;
}