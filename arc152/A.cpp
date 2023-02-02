/**
 *      Author:  nicksms
 *      Created: 01.13.2023 21:21:27
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L; cin >> N >> L;
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    int tot = 0;
    int last = 1;
    for (int i = 1; i <= N; i++) {
        if (a[i] + tot == L) {
            last = i+1;
            break;
        } else if (a[i] + tot > L) {
            last = i;
            break;
        } else {
            tot += a[i] + 1;
            last = i;
        }
    }
    for (int i = last; i <= N; i++) {
        if (a[i] == 2) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}