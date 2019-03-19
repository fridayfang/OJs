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
int n,m;
int mmp[10][10];
int vis[10][10];
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int sx,sy;
//dfs 不能做，dfs一定要打标记，否则陷入循环出不来
//bfs可以打标记，也可以不打标记，因为逐层扩展
struct Node{
    int x,y,step,timing;
    Node(){}
    Node(int _x,int _y,int _s,int _t):x(_x),y(_y),step(_s),timing(_t){}
};
int bfs(){
    queue<Node> q;
    q.push(Node(sx,sy,0,6));
    while(!q.empty()){
        Node tmp=q.front();q.pop();
        int x=tmp.x,y=tmp.y,s=tmp.step,t=tmp.timing;
        //db(x),db(y),db(s),db(t);
        if(mmp[x][y]==3&&t>0)return s;
        if(t>0){
            for(int i=0;i<4;i++){
                int nx=x+mv[i][0],ny=y+mv[i][1];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(mmp[nx][ny]==1||mmp[nx][ny]==3)q.push(Node(nx,ny,s+1,t-1));
                    else if(mmp[nx][ny]==4&&t>=2&&!vis[nx][ny]){q.push(Node(nx,ny,s+1,6));vis[nx][ny]=1;}
                }
                
            }
        }
    }
    return -1;
}


int main(){
    int t;sf(t);
    while(t--){
        scanf("%d %d",&n,&m);
        CL(vis,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sf(mmp[i][j]);
                if(mmp[i][j]==2){sx=i,sy=j;}
            }
        }
        int ans=bfs();
        pr(ans);

    }
    
    return 0;
}