/**
 *      Author:  nicksms
 *      Created: 02.01.2023 15:39:41
 *      This solution is actually just straight up incorrect I think. I'm pretty sure the testcases are just weak. Maybe there is something about 20^4 ~= 10^6 that makes this work though.
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W; cin >> H >> W;
    vector<vector<int>> M(H, vector<int>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> M[i][j];
    vector<int> rmins(H);
    vector<int> rmaxs(H);
    vector<pair<int,int>> rowcheck;
    for (int i = 0; i < H; i++) { 
        for (int j = 0; j < W; j++) {
            rmins[i] = rmins[i] && M[i][j] ? min(rmins[i], M[i][j]) : max(rmins[i], M[i][j]);
            rmaxs[i] = max(rmaxs[i], M[i][j]);
        }
        rowcheck.emplace_back(rmins[i], rmaxs[i]);
    }
    sort(rowcheck.begin(), rowcheck.end());
    // for (auto &&p : rowcheck) cout << p.first << " " << p.second << endl;
    for (int i = 0; i < H-1; i++) {
        if (rowcheck[i].second > rowcheck[i+1].first) {
            cout << "No\n";
            return 0;
        }
    }
    vector<int> colcheck(W);
    for (int i = 0; i < W; i++) colcheck[i] = i;
    for (int _ = 0; _ < 20; _++) // fucking kill me
    for (int i = 0; i < H; i++) {
        vector<int> nzi;
        for (int j = 0; j < W; j++) if (M[i][colcheck[j]]) nzi.push_back(j);
        const vector<int> nzio = nzi;
        const vector<int> cco = colcheck;
        stable_sort(nzi.begin(), nzi.end(), [&](int a, int b) -> bool {
            return M[i][colcheck[a]] < M[i][colcheck[b]];
        });
        for (int j = 0; j < nzi.size(); j++) colcheck[nzio[j]] = cco[nzi[j]];
    }
    const vector<int> cc = colcheck;
    for (int i = 0; i < H; i++) {
        // for (auto &&p : colcheck) cout << p << " ";
        vector<int> nzi;
        for (int j = 0; j < W; j++) if (M[i][colcheck[j]]) nzi.push_back(j);
        const vector<int> nzio = nzi;
        stable_sort(nzi.begin(), nzi.end(), [&](int a, int b) -> bool {
            return M[i][colcheck[a]] < M[i][colcheck[b]];
        });
        // for (auto &&p : colcheck) cout << p << " ";
        if (nzio != nzi) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}