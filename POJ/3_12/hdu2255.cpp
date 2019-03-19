#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define name2str(name) (#name)
#define db(x) cout<<#x"=["<<(x)<<"]"<<endl
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define rng(a) a.begin(),a.end()
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
//author:fridayfang
//date:19 3月 12
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 300 + 5;
const int maxm = 1e6+5;
//先试试O(n^4)写法
 int lx[maxn],ly[maxn];
 int mat[maxn][maxn];
 int n;
 int visx[maxn],visy[maxn];
 int linker[maxn];
 
 bool dfs(int u){
     visx[u]=1;
     for(int i=1;i<=n;i++){
         if(!visy[i]&&(lx[u]+ly[i]==mat[u][i])){
             visy[i]=1;
             if(linker[i]==-1||dfs(linker[i])){
                 linker[i]=u;return true;
             }
         }
     }
     return false;
 }
 int km(){
     CL(linker,-1),CL(lx,0),CL(ly,0);
     for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             lx[i]=max(lx[i],mat[i][j]);
         }
     }
     for(int i=1;i<=n;i++){
         while(true){
             CL(visx,0),CL(visy,0);
             if(dfs(i))break;
             int d=inf;
             for(int x=1;x<=n;x++){
                 for(int y=1;y<=n;y++){
                     if(visx[x]&&!visy[y])d=min(d,lx[x]+ly[y]-mat[x][y]);
                 }
             }
             for(int i=1;i<=n;i++){
                 if(visx[i])lx[i]-=d;
                 if(visy[i])ly[i]+=d;
             }
         }
     }
     int res=0;
     for(int i=1;i<=n;i++){
         res+=mat[linker[i]][i];
     }
     return res;
 }



int main(){
    while(~sf(n)){
        fr1(i,n)fr1(j,n)sf(mat[i][j]);
        int ans=km();
        pr(ans);
    }
    
    return 0;
}