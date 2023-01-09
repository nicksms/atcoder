/**
 *      Author:  nicksms
 *      Created: 01.07.2023 21:51:12
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    stack<bitset<26>> st;
    bitset<26> bc;
    for (int i = 0; i < s.size(); i++) {
        char cur = s[i];
        if ('a' <= cur && cur <= 'z') {
            if (bc[cur-'a']) {
                cout << "No\n";
                return 0;
            } else bc[cur-'a'] = true;
        } else if (cur == '(') {
            st.push(bc);
        } else {
            bc = st.top();
            st.pop();
        }
    }
    cout << "Yes";
    return 0;
}