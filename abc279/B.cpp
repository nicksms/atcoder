/**
 *      Author:  nicksms
 *      Created: 01.10.2023 06:12:52
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


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

bool substr(string t, string s) {
    auto v = z_function(s,t);
    if (s.length() < t.length()) return false;
    for (int i = 0; i+t.length()-1 < s.length(); i++) {
        if (v[i] >= t.length()) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t; cin >> s >> t;
    cout << (substr(t,s) ? "Yes" : "No") << "\n";
    return 0;
}