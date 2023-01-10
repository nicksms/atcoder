/**
 *      Author:  nicksms
 *      Created: 01.10.2023 08:08:55
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<int> A(M+1);
    for (int i = 1; i <= M; i++) cin >> A[i];
    vector<int> rpart(N+1); for (int i = 1; i <= N; i++) rpart[i]=i;
    vector<int> rinv(N+1); for (int i = 1; i <= N; i++) rinv[i]=i;
    for (int i = M; i > 1; i--) {
        int inda = rinv[A[i]];
        int indb = rinv[A[i]+1];
        swap(rinv[A[i]],rinv[A[i]+1]);
        swap(rpart[inda],rpart[indb]);
    }
    vector<int> lpart(N+1); for (int i = 1; i <= N; i++) lpart[i]=i;
    vector<int> linv(N+1); for (int i = 1; i <= N; i++) linv[i]=i;
    for (int i = 1; i <= M; i++) {
        cout << rinv[linv[1]] << "\n";
        if (i < M) { 
            int inda = rinv[A[i+1]];
            int indb = rinv[A[i+1]+1];
            swap(rinv[A[i+1]],rinv[A[i+1]+1]);
            swap(rpart[inda], rpart[indb]);
        }
        swap(lpart[A[i]],lpart[A[i]+1]);
        linv[lpart[A[i]]] = A[i];
        linv[lpart[A[i]+1]] = A[i]+1;
    }
    return 0;
}