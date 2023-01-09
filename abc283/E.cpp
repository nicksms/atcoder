/**
 *      Author:  nicksms
 *      Created: 01.08.2023 07:53:47
 *      DOES NOT WORK
**/

#include <bits/stdc++.h>
using namespace std;

bool getshouldflip(const vector<vector<int>>& m, int r, int H, int W) {
    vector<bool> bad(m[r].size());
    for (int i = 0; i < W; i++) {
        bad[i] = true;
        if (i < W-1) {
            bad[i] = bad[i] && ( m[r][i] != m[r][i+1] );
        }
        if (i > 0) {
            bad[i] = bad[i] && ( m[r][i] != m[r][i-1] );
        }
        if (r > 0) {
            bad[i] = bad[i] && ( m[r][i] != m[r-1][i] );
        }
        if (r < H-1) {
            bad[i] = bad[i] && ( m[r][i] != m[r+1][i] );
        }
        // cout << r << " " << i << bad[i] << endl;
        if (bad[i]) return true;
    }
    return false;
}

void flip(vector<vector<int>>& m, int r, int H, int W) {
    for (int i = 0; i < W; i++) {
        m[r][i] = 1-m[r][i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<vector<int>> m(H);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int c; cin >> c; m[i].push_back(c);
        }
    }
    // cout << getshouldflip(m,0,H,W) << endl;
    vector<vector<vector<int>>> best(H, vector<vector<int>>(2, vector<int>(2,1e9)));
    best[0][0][0] = 0;
    best[0][1][0] = 1;
    best[0][0][1] = 0;
    best[0][1][1] = 1;
    //  cout<<"HI"<<endl;
    for (int i = 0; i < H-1; i++) {
        for (int flipcur = 0; flipcur < 2; flipcur++) {
            if (i > 0) {
                for (int flipbefore = 0; flipbefore < 2; flipbefore++) {
                    for (int flipnext = 0; flipnext < 2; flipnext++) {
                        if (flipbefore) {
                            flip(m,i-1,H,W);
                        }
                        if (flipcur) {
                            flip(m, i, H, W);
                        }
                        if (flipnext) {
                            flip(m, i+1, H, W);
                        }
                        if (!getshouldflip(m, i, H, W)) {
                            best[i+1][flipnext][flipcur] = min(best[i+1][flipnext][flipcur], flipnext + best[i][flipcur][flipbefore]);
                        }
                        if (flipnext) {
                            flip(m, i+1, H, W);
                        }
                        if (flipcur) {
                            flip(m, i, H, W);
                        }
                        if (flipbefore) {
                            flip(m,i-1,H,W);
                        }
                    }
                }
            } else {
                if (flipcur) {
                    flip(m, i, H, W);
                }
                // cout << flipcur << " " << getshouldflip(m, i, H, W) << endl;
                if (getshouldflip(m, i, H, W)) {
                    flip(m,i+1,H,W);
                    if (!getshouldflip(m,i,H,W)) {
                        best[i+1][1][flipcur] = 1+best[i][flipcur][0];
                    }
                    flip(m,i+1,H,W);
                } else {
                    if (!getshouldflip(m,i,H,W)) {
                        best[i+1][0][flipcur] = best[i][flipcur][0];
                    }
                }
                if (flipcur) {
                    flip(m, i, H, W);
                }
            }
        }
    }
    int ans = 1000000000;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
            if (j) {
                flip(m,H-1,H,W);
            }
            if (k) {
                flip(m,H-2,H,W);
            }
            if (!getshouldflip(m,H-1,H,W)) {
                ans = min(ans, best[H-1][j][k]);
            }
            if (k) {
                flip(m,H-2,H,W);
            }
            if (j) {
                flip(m,H-1,H,W);
            }
        }
    }
    // for(int i=0;i<H;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<best[i][j][0]<<" "<<best[i][j][1]<<"\t";
    //     }
    //     cout<<endl;
    // }
    ans = ans > 1000 ? -1 : ans;
    cout << ans << "\n";
    return 0;
}