/**
 *      Author:  nicksms
 *      Created: 02.02.2023 12:26:59
**/

#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<int,int>> L(N+1);
    set<int> app;
    for (int i = 1; i <= N; i++) {
        cin >> L[i].first >> L[i].second;
        app.insert(L[i].first);
        app.insert(L[i].second);
    }
    if (!app.count(1)) {
        cout << "1\n";
        return 0;
    }
    int n = 0;
    map<int, int> rev;
    for (int k : app) rev[k] = n++;
    atcoder::dsu d(n);
    for (int i = 1; i <= N; i++) {
        d.merge(rev[L[i].first], rev[L[i].second]);
    }
    int best = 1;
    for (int k : app) if (d.same(rev[1], rev[k])) best = k;
    cout << best << "\n";
    return 0;
}