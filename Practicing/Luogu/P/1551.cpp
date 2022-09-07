#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5001;
int fa[MAXN],ranks[MAXN];
int n, m, p, x, y;

inline void init(int n){
    for(int i = 1;i <= n;i++){
        fa[i] = i;
        ranks[i] = 1;
    }
}
inline int find(int i){
   return i == fa[i] ? i : (fa[i] = find(fa[i]));
}
inline void merge(int i,int j){
    fa[find(i)] = find(j);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p;
    init(n);
    for(int i = 0;i < m;i++){
        cin >> x >> y;
        merge(x,y);
    }
    for(int i = 0;i < p;i++){
        cin >> x >> y;
        cout << (find(x) == find(y) ? "Yes" : "No") << endl;
    }

    return 0;
}