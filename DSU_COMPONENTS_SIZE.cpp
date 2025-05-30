//finding number of componets at each query and updating size of each group
// problem link - > https://cses.fi/problemset/task/1676
// submisson link -> https://cses.fi/problemset/result/13113560/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
const char nl = '\n';
int Parent[N];
int Size[N];
void Make(int child){
    Parent[child] = child;
    Size[child] = 1;
}
int Find(int v){
    if(v == Parent[v]) return v;
    return Parent[v] = Find(Parent[v]);
}
void Union(int a , int b){
    a = Find(a);
    b = Find(b);
    if(a != b){
        if(Size[a] < Size[b])
            swap(a , b);
        Parent[b] = a;
        Size[a] += Size[b];
    }
}
void solve(){
    int n , q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        Make(i);
    }
    int max_size = 1;
    int x , y;
    int connected_components = n;
    while(q--){
        cin >> x >> y;
        x = Find(x);
        y = Find(y);
        Union(x , y);
        if(x != y){
            connected_components--;
        }
        max_size = max(max_size , max(Size[x] , Size[y]));
        cout<<connected_components<<" "<<max_size<<endl;
    }
}
int main(){
 auto begin = std::chrono::high_resolution_clock::now();
//  FIO
 int t = 1;
//   cin >> t;
 while(t--)
 solve();
 auto end = std::chrono::high_resolution_clock::now();
 auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
 return 0;
}
