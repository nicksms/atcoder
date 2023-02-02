/**
 *      Author:  nicksms
 *      Created: 01.12.2023 14:05:47
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int grund[2001];
pair<int,int> grundify[2001][2001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L, R;
    cin >> N >> L >> R;
    for (int n = 0; n <= N; n++) {
        for (int k = 0; k <= N; k++) {
            grundify[n][k] = {-1, -1};
        }
    }
    for (int n = 1; n <= N; n++) {
        for (int j = 0; j <= 2000; j++) {
            grundify[n][j] = grundify[n-1][j];
        }
        for (int l = 0; l <= n-L; l++) {
            int r = n-L-l;
            int g = grund[l] ^ grund[r];
            grundify[n][g] = {l, r}; 
        }
        for (int g = 0; g <= N; g++) {
            if (grundify[n][g].first + grundify[n][g].second < n-R) {
                grundify[n][g] = {-1,-1};
            }
        }
        for (int g = 0; g <= N; g++) {
            if (grundify[n][g] == pair<int,int>{-1,-1}) {
                grund[n] = g;
                break;
            }
        }
    }
    bool b = false;
    if (!grund[N]) {
        cout << "Second" << endl;
        b = true;
    } else {
        cout << "First" << endl;
    }
    vector<pair<int,int>> states(1,{1, N});
    int grundy = grund[N];
    while (true) {
        if (b) {
            int x, y; cin >> x >> y;
            if (x < 1 && y < 1) break;
            for (int i = 0; i < states.size(); i++) {
                if (states[i].first <= x && states[i].second >= x) {
                    auto [f,s] = states[i];
                    states.erase(states.begin()+i);
                    grundy ^= grund[s-f+1];
                    grundy ^= grund[x-f];
                    grundy ^= grund[s-x-y+1];
                    if (f < x) {
                        states.emplace_back(f, x-1);
                    }
                    if (x+y <= s) {
                        states.emplace_back(x+y,s);
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < states.size(); i++) {
            int le = states[i].second - states[i].first + 1;
            if (grundify[le][grund[le] ^ grundy] != pair<int,int>{-1,-1}) {
                auto [f,s] = states[i];
                int x = f + grundify[le][grund[le] ^ grundy].first;
                int y = s-f+1 - (grundify[le][grund[le] ^ grundy].first + grundify[le][grund[le] ^ grundy].second);
                states.erase(states.begin()+i);
                grundy ^= grund[s-f+1];
                grundy ^= grund[x-f];
                grundy ^= grund[s-x-y+1];
                if (f < x) {
                    states.emplace_back(f, x-1);
                }
                if (x+y <= s) {
                    states.emplace_back(x+y,s);
                }
                cout << x << " " << y << endl;
                break;
            }
        }
        b = true;
    }

    return 0;
}