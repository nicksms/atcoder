/**
 *      Author:  nicksms
 *      Created: 01.14.2023 07:26:41
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    if (N == 1) {
        cout << "Yes\n0\n";
        return 0;
    }
    vector<ll> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    vector<ll> p(N+1);
    for (int i = 1; i <= N; i++) {
        p[i] = p[i-1]+A[i];
    }
    ll tot = 0;
    for (int i = 1; i < N; i++) {
        tot += p[i];
    }
    vector<ll> pans(N+1);
    if (p[N] == 0) {
        if (tot != 0) {
            if (tot > 0) {
                bool b = true;
                int ind = 0;
                for (int i = 1; i < N; i++) {
                    if (p[i] == -1) {
                        b = false;
                        ind = i;
                        break;
                    }
                }
                if (b) {
                    cout << "No\n";
                    return 0;
                } else {
                    pans[ind] += tot;
                    // if (ind > 0) pans[ind-1] += tot;
                }
            } else {
                bool b = true;
                int ind = 0;
                for (int i = 1; i < N; i++) {
                    if (p[i] == 1) {
                        b = false;
                        ind = i;
                        break;
                    }
                }
                if (b) {
                    cout << "No\n";
                    return 0;
                } else {
                    pans[ind] -= tot;
                    // if (ind > 0) pans[ind-1] += tot;
                }
            }
        }
    } else {
        if (A[1] == 1) {
            while (pans[N]*p[N] - tot <= 0) {
                pans[N] += (p[N] > 0 ? 1 : -1);
            }
            pans[1] += pans[N]*p[N] - tot;

        } else {
            
            while (pans[N]*p[N] - tot >= 0) {
                pans[N] += (p[N] > 0 ? -1 : 1);
            }
            pans[1] -= pans[N]*p[N] - tot;
        }
    }
    vector<ll> ans(N+1);
    ans[N] = pans[N];
    for (int i = N-1; i > 0; i--) {
        ans[i] = ans[i+1] - (pans[i]+1);
    }
    cout << "Yes\n";
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}