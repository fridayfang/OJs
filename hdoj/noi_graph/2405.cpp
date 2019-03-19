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
//date:19 3月 11
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e2 + 5;
const int maxm = 1e6+5;
int mpp[maxn][maxn];
int n,m,k;
int vis[maxn][maxn];
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
// when call vis[sx][sy]=1
int dfs(int sx,int sy){
    //db(sx),db(sy);
    
    int ans=1;
    for(int i=0;i<4;i++){
        int nx=sx+mv[i][0],ny=sy+mv[i][1];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mpp[nx][ny]==1&&!vis[nx][ny]){
            vis[nx][ny]=1;
            ans+=dfs(nx,ny);
        }
    }
   // db(ans);
    return ans;
}
struct Point{int x,y;}p[10000];
int main(){
    sf(n),sf(m),sf(k);
    fr0(i,k){int x,y;sf(x),sf(y);mpp[x][y]=1,p[i].x=x,p[i].y=y;}
    int maxl=0;
    CL(vis,0);
    for(int i=0;i<k;i++){
        int x=p[i].x,y=p[i].y;
        if(!vis[x][y]){
            vis[x][y]=1;
            //db(x),db(y);
            maxl=max(maxl,dfs(x,y));
            //db(maxl);
        }
    }
    pr(maxl);
    
    return 0;
}