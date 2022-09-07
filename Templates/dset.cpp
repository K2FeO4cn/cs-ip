#include <bits/stdc++.h>
using namespace std;
/*
* Algorithm 算法: Disjoint Set 并查集
* Template 模板题: Luogu P 1551
*/

const int MAXN = 5001;
int fa[MAXN],ranks[MAXN];

inline void init(int n){
    for(int i = 1;i <= n;i++){
        fa[i] = i;
        ranks[i] = 1;
    }
}

inline int find(int i){
    /*Without Path Compressin 无路径压缩
    if (fa[i] == i) return i;
    return find(fa[i]);
    */
   // Path Compression Included 路径压缩
   return i == fa[i] ? i : (fa[i] = find(fa[i]));
}
inline void merge(int i,int j){
    fa[find(i)] = find(j);
    /* Merge by rank 按秩合并
    int x = find(i), y = find(j);
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++;
    */
}

// For Template Code Belows Here 为模板题的代码在此之下

int n, m, p, x, y;

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