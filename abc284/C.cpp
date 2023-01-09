/**
 *      Author:  nicksms
 *      Created: 01.07.2023 06:30:38
**/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/dsu>
using dsu = atcoder::dsu;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    dsu d = dsu(n);
    int tot = n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (!d.same(a-1,b-1)) {
            d.merge(a-1,b-1);
            tot--;
        }
    }
    cout << tot << endl;
    return 0;
}