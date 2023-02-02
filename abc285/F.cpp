/**
 *      Author:  nicksms
 *      Created: 01.15.2023 07:36:56
**/

#include <bits/stdc++.h>
#include <atcoder/segtree>
struct substr {
    int f[26];
    bool s;
};
substr e() {
    substr s;
    for (int i = 0; i < 26; i++) s.f[i] = 0;
    s.s = true;
    return s;
}
substr op(substr a, substr b) {
    substr s;
    int lnza = 0;
    int fnzb = 0; bool fb = false;
    for (int i = 0; i < 26; i++) {
        s.f[i] = a.f[i] + b.f[i];
        if (a.f[i]) lnza = i;
        if (b.f[i] && !fb) {
            fb = true;
            fnzb = i;
        }
    }
    s.s = a.s && b.s && (lnza <= fnzb || (!fb));
    return s;
}
using st = atcoder::segtree<substr, op, e>;
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    string S; cin >> S;
    st sg(N+1);
    for (int i = 1; i <= N; i++) {
        substr s = e();
        s.f[S[i-1]-'a'] = 1;
        sg.set(i, s);
    } 
    int Q; cin >> Q;
    while (Q--) {
        int code; cin >> code;
        if (code == 1) {
            int x; string c; cin >> x >> c;
            substr s = e();
            s.f[c[0]-'a'] = 1;
            sg.set(x, s);
        } else {
            int l, r; cin >> l >> r;
            substr s = sg.prod(l, r+1);
            // for (int i = 0; i < 26; i++) cout << s.f[i] << " ";
            // cout << s.s << endl;
            substr a = sg.prod(1, N+1);
            // for (int i = 0; i < 26; i++) cout << a.f[i] << " ";
            // cout << a.s << endl;
            bool b = s.s;
            if (b) {
                int fnz = 0, lnz = 0; bool fb = false;
                for (int i = 0; i < 26; i++) {
                    if (s.f[i]) {
                        if (!fb) {
                            fb = true;
                            fnz = i;
                        }
                        lnz = i;
                    }
                }
                for (int i = fnz+1; i < lnz && b; i++) {
                    b = b && (s.f[i] == a.f[i]);
                }
            }
            cout << (b ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}