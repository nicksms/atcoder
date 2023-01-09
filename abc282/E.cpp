/**
 *      Author:  nicksms
 *      Created: 01.05.2023 08:56:33
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct dsu{
    int N;
    vector<int> p, s;
    dsu(int _n){
        N = _n + 5;
        p.resize(N); s.resize(N);
        iota(p.begin(), p.end(), 0);
        fill(s.begin(), s.end(), 1);
    }
    int find(int a){
        if(p[a] == a) return a;
        p[a] = find(p[a]);
        return p[a];
    }
    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(s[a] > s[b]) swap(a, b);
        s[b] += s[a];
        p[a] = b;
        return true;
    }
    bool same(int a, int b){
        return find(a) == find(b);
    }
};

ll modpow(ll a, ll b, ll m) {
    ll ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
    }
    return ans;
}

struct edge {
    int s;
    int t;
    int w;
};

bool operator<(edge a, edge b) {return a.w > b.w;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<edge> edges(n*n - n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) edges[k++] = edge{i, j, (int)((0LL + modpow(a[i],a[j],(ll)m) + modpow(a[j],a[i],(ll)m))%m)};
        }
    }
    sort(edges.begin(),edges.end());
    dsu d(n);
    ll tot = 0;
    for (edge e : edges) {
        if (!d.same(e.s,e.t)) {
            tot += e.w;
            d.unite(e.s,e.t);
        }
    }
    cout << tot << endl;
    

    return 0;
}