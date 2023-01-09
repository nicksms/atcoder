/**
 *      Author:  nicksms
 *      Created: 01.06.2023 20:11:05
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int tot = 0;
    stack<pair<int, int>> s;
    while (n--) {
        int k; cin >> k;
        tot += 1;
        if (!s.empty() && s.top().first == k) {
            int r = s.top().second;
            s.pop();
            r += 1;
            if (r == k) {
                tot -= k;
            } else {
                s.push(pair<int,int>{k,r});
            }
        } else {
            s.push(pair<int,int>{k,1});
        }
        cout << tot << "\n";
    }
    return 0;
}