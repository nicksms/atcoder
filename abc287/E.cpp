/**
 *      Author:  nicksms
 *      Created: 01.31.2023 12:37:13
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<string> ss(N);
    for (int i = 0; i < N; i++) cin >> ss[i];
    auto so = ss;
    sort(ss.begin(), ss.end());
    unordered_map<string, int> tr;
    for (int i = 0; i < N; i++) tr[ss[i]] = i;
    vector<int> best(N);
    auto lcp = [](const string &a, const string &b) -> int {
        int i = 0;
        while (i < a.size() && i < b.size() && (a[i] == b[i])) i++;
        return i;
    };
    for (int i = 1; i < N; i++) {
        int l = lcp(ss[i], ss[i-1]);
        best[i-1] = max(best[i-1], l);
        best[i] = max(best[i], l);
    }
    for (string s : so) cout << best[tr[s]] << "\n";

    return 0;
}