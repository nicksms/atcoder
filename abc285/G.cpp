/**
 *      Author:  nicksms
 *      Created: 01.16.2023 19:12:32
 *      Had to look at editorial for this one
**/

#include <bits/stdc++.h>
#include <atcoder/maxflow>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W; cin >> H >> W;

    atcoder::mf_graph<int> g(H*W + 4);
    vector<string> b(H); for (int h = 0; h < H; h++) cin >> b[h];
    int s = H*W; int t = s+1; 
    int sp = s+2; int tp = sp+1;
    int to = 0, te = 0; // ol, er
    for (int h = 0; h < H; h++) {
        for (int w = 1 - (h % 2); w < W; w += 2) {
            if (b[h][w] == '1') continue;
            if (b[h][w] == '2') {
                g.add_edge(sp, h*W + w, 1);
                to++;
            } else {
                g.add_edge(s, h*W + w, 1);
            }
            if (h - 1 >= 0 && b[h-1][w] != '1') g.add_edge(h*W+w, (h-1)*W+w, 1);
            if (w - 1 >= 0 && b[h][w-1] != '1') g.add_edge(h*W+w, (h)*W+w-1, 1);
            if (h + 1 < H && b[h+1][w] != '1') g.add_edge(h*W+w, (h+1)*W+w, 1);
            if (w + 1 < W && b[h][w+1] != '1') g.add_edge(h*W+w, (h)*W+w+1, 1);
        }
        for (int w = h % 2; w < W; w += 2) {
            if (b[h][w] == '2') {
                g.add_edge(h*W + w, tp, 1);
                te++;
            } else if (b[h][w] == '?') {
                g.add_edge(h*W + w, t, 1);
            }
        }
    }
    g.add_edge(s, tp, to);
    g.add_edge(sp, t, te);
    g.add_edge(t, s, 5*H*W);
    if (g.flow(sp, tp) == to + te) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}