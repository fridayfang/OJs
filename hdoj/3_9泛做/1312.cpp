#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
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
//date:19 3月 09
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;

int n,m,cnt;//n rows
char mmp[25][25];
int vis[25][25];
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int sx,sy;
//vis[][] first when call
void dfs(int curx,int cury){
    cnt++;
    for(int i=0;i<4;i++){
        int nx=curx+mv[i][0],ny=cury+mv[i][1];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&mmp[nx][ny]=='.'){
            vis[nx][ny]=1;
            dfs(nx,ny);
        }
    }

}

int main(){
    while(scanf("%d %d",&m,&n)&&n){
        CL(vis,0);cnt=0;
        for(int i=0;i<n;i++){
            scanf("%s",mmp[i]);
            for(int j=0;j<m;j++){
                if(mmp[i][j]=='@'){sx=i,sy=j;}
            }
        }
        vis[sx][sy]=1;
        dfs(sx,sy);
        printf("%d\n",cnt);

    }
    
    return 0;
}