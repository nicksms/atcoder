/**
 *      Author:  nicksms
 *      Created: 01.06.2023 21:02:54
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,m; cin >> n >> m;
        vector<ll> x(n+1);
        vector<ll> y(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        ll best = x[1];
        ll lastb = 0;
        ll lasta = 0;
        for (int i = 1; i <= n; i++) {
            // cout << i << " " << lasta << " " << lastb << " " << best << endl;
            auto eval = [&](ll xx){return lasta + xx*lastb + x[i]*(((xx)*(xx+1))/2);};
            if (i > 1) best = max(best, eval(0));
            best = max(best, eval(1));
            best = max(best, eval(y[i]));
            if (x[i] != 0) {
                #define normalizeok(nn) min(y[i], max(0LL, nn))
                ll crit1 = -lastb/x[i];
                for (ll crit = crit1-10; crit <= crit1+10; crit++) {
                    if (normalizeok(crit) > 0 || i > 1) best = max(best, eval(normalizeok(crit)));
                }
            }
            lasta += y[i]*lastb + x[i]*(((y[i])*(y[i]+1))/2);
            lastb += y[i]*x[i];
        }
        cout << best << "\n";
    }
    return 0;
}