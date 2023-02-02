/**
 *      Author:  nicksms
 *      Created: 01.12.2023 10:16:45
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, M; cin >> H >> M;
    auto cs = [](int h, int m) -> bool {
        return (stoi(to_string(100+h).substr(1,1) + to_string(100+m).substr(1,1)) < 24) && (stoi(to_string(100+h).substr(2,1) + to_string(100+m).substr(2,1)) < 60);
    };
    while (true) {
        if (cs(H, M)) {
            cout << H << " " << M << "\n";
            return 0;
        }
        M += 1;
        H += M/60;
        M %= 60;
        H %= 24;
    }
    return 0;
}