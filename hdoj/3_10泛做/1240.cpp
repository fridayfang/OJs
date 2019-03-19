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
char mpp[12][12][12];
int dis[12][12][12];
int n;
int sx,sy,sz,dx,dy,dz;
struct node{
    int x,y,z,step;
    node(){}
    node(int _x,int _y,int _z,int _s):x(_x),y(_y),z(_z),step(_s){}
};
int mv[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

int vis[12][12][12];
int bfs(){
    queue<node> q;q.push(node(sx,sy,sz,0));vis[0][0][0]=1;
    while(!q.empty()){
        node tmp=q.front();q.pop();
        int cx=tmp.x,cy=tmp.y,cz=tmp.z,s=tmp.step;
        if(cx==dx&&cy==dy&&cz==dz) return s;
        for(int i=0;i<6;i++){
            int nx=cx+mv[i][0],ny=cy+mv[i][1],nz=cz+mv[i][2];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&nz>=0&&nz<n&&!vis[nx][ny][nz]&&mpp[nx][ny][nz]!='X'){
                vis[nx][ny][nz]=1;
                q.push(node(nx,ny,nz,s+1));
            }
        }
    }
    return -1;
}

char tmp[20];
int main(){
    while(~scanf("%s",tmp)){
        sf(n);CL(vis,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%s",mpp[i][j]);
               // printf("%s",mpp[i][j]);
            }
        }
        sf(sy),sf(sz),sf(sx),sf(dy),sf(dz),sf(dx);
        scanf("%s",tmp);
        int ans=bfs();
        if(ans==-1)printf("NO ROUTE\n");
        else printf("%d %d\n",n,ans);
    }
    
    return 0;
}