//Disjoint set Union with lazy path compression 

//problem link 
//    https://judge.yosupo.jp/problem/unionfind
// submission link
// https://judge.yosupo.jp/submissions/?problem=unionfind&user=gondsachin40&status=AC
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
int Parent[N];
int Size[N];
void Make(int child){
    Parent[child] = child;
    Size[child] = 1;
}
int Find(int v){
    if(v == Parent[v]) return v;
    //path compression
    return Parent[v] = Find(Parent[v]);
}
void Union(int a , int b){
    a = Find(a);
    b = Find(b);
    if(a != b){
        if(Size[a] < Size[b])
            swap(a , b);
        Parent[b] = a;
        Size[b] += Size[a];
    }
}
void solve(){
    int n , q;
    cin >> n >> q;
    for(int i = 0;i<n;i++){
        Make(i);
    }
    int x , u , v;
    while(q--){
        cin >> x >> u >> v;
        if(x == 0){
            int a = Find(u);
            int b = Find(v);
            Union(a , b);
        }else{
            int a = Find(u);
            int b = Find(v);
            cout<<(a == b)<<'\n';
        }
    }
}
int main(){
 int t = 1;
//   cin >> t;
 while(t--)
 solve();
}
