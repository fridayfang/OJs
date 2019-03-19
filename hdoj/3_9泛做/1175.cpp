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
//date:19 3月 10
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;

int mpp[1010][1010],c[1010][1010],vis[1010][1010];///record the number of cut from sx sy
int sx,sy,dx,dy,n,m;
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int dfs(int curx,int cury,int cuts,int dir){
    if(curx==dx&&cury==dy&&cuts<=2){return 1;}//ok
    if(cuts>2){return 0;}
    if(cuts!=-1&&mpp[curx][cury]){return 0;}

    if(c[curx][cury]<cuts){return 0;}
    else {c[curx][cury]=cuts;}
    for(int i=0;i<4;i++){
        int nx=curx+mv[i][0],ny=cury+mv[i][1];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]){
            vis[nx][ny]=1;
            if(dir==i){if(dfs(nx,ny,cuts,dir))return 1;}
            else{if(dfs(nx,ny,cuts+1,i))return 1;}
            vis[nx][ny]=0;
        }
    }
    return 0;
}

int main(){
    while(scanf("%d %d",&n,&m)&&n){
        CL(c,inf),CL(vis,0);
        fr0(i,n){
            fr0(j,m){
                sf(mpp[i][j]);

            }
        }
        int t;sf(t);
        while(t--){
            CL(c,inf);
            CL(vis,0);
            sf(sx),sf(sy),sf(dx),sf(dy);
            sx--,sy--,dx--,dy--;
            if(mpp[sx][sy]!=mpp[dx][dy]||mpp[sx][sy]==0){printf("NO\n");continue;}
            else{
                //db(sx),db(sy);
                vis[sx][sy]=1;
                int ans=dfs(sx,sy,-1,5);
                if(ans){printf("YES\n");}
                else printf("NO\n");
            }
        }
    }
    return 0;
}