/**
 *      Author:  nicksms
 *      Created: 01.07.2023 06:31:03
**/

#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> z_function(string s, string in) {
    int a = in.size();
    int b = s.size();
    in.append(s);
    vector<int> ans = z_function(in);
    vector<int> ans2(b);
    for (int i = a; i < ans.size(); i++) {
        ans2[i-a] = ans[i];
    }
    return ans2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    string r;
    reverse_copy(s.begin(), s.end(), back_inserter(r));
    vector<int> z1 = z_function(s, r);
    vector<int> z2 = z_function(r, s);
    for (int i = 0; i <= n; i++) {
        if (z1[i] >= n-i &&  z2[n-i] >= i) {
            string ans = s.substr(0,i);
            if (n-i > 0) ans.append(s.substr(2*n - (n-i),n-i));
            cout << ans << "\n" << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}