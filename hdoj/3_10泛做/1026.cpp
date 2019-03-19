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

int n,m;
char mpp[110][110];int dis[110][110];
int path[110][110];//记录方向生成路径
int mv[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    int x,y,step,dir;
    node(){}
    node(int _x,int _y,int _s,int _dir):x(_x),y(_y),step(_s),dir(_dir){}
    bool friend operator <(node n1,node n2){
        return n1.step>n2.step;
    }
};
int sx,sy,dx,dy;
int bfs(){
    priority_queue<node> q;q.push(node(0,0,0,-1));
    while(!q.empty()){
        node tmp=q.top();q.pop();
        int cx=tmp.x,cy=tmp.y,cs=tmp.step,dir=tmp.dir;
        
        if(cs<dis[cx][cy]){dis[cx][cy]=cs;path[cx][cy]=dir;}
        else continue;//非常重要的内存剪枝手段，因为如果队列中同时存在多个相同坐标的节点，但当我们已经知道了最短距离，不需对>最短距离的节点进行扩展
        if(cx==dx&&cy==dy)return cs;
        for(int i=0;i<4;i++){
            int nx=cx+mv[i][0],ny=cy+mv[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&dis[nx][ny]==inf&&mpp[nx][ny]!='X'){//表示未出队列
                if(mpp[nx][ny]=='.')q.push(node(nx,ny,cs+1,i));
                else if(mpp[nx][ny]>='0'&&mpp[nx][ny]<='9')q.push(node(nx,ny,cs+1+mpp[nx][ny]-'0',i));
            }
        }
    }
    return -1;
}
vector<pair<int,int>> vp;//record path
void build(){
    vp.clear();
    int curx=dx,cury=dy,curd=path[dx][dy];
    while(curx!=sx||cury!=sy){
        vp.push_back(make_pair(curx,cury));
        curx=curx-mv[curd][0],cury=cury-mv[curd][1];
        curd=path[curx][cury];
    }
    vp.push_back(make_pair(0,0));
    int sz=vp.size();
    //db(sz);
    int cnt=0;
    for(int j=sz-1;j>=0;j--){
        int x=vp[j].first,y=vp[j].second;
        if(mpp[x][y]>='0'&&mpp[x][y]<='9'){
            int num=mpp[x][y]-'0';
            for(int i=1;i<=num;i++){
                cnt++;
                printf("%ds:FIGHT AT (%d,%d)\n",cnt,x,y);
            }
            
        }
        cnt++;
        if(j>0)printf("%ds:(%d,%d)->(%d,%d)\n",cnt,vp[j].first,vp[j].second,vp[j-1].first,vp[j-1].second);
    }
    printf("FINISH\n");
}
int main(){
    while(~scanf("%d %d",&n,&m)){
        fr0(i,n){
            scanf("%s",mpp[i]);
        }
        sx=0,sy=0,dx=n-1,dy=m-1;
        CL(dis,inf);
        int ans=bfs();
        if(ans>=0){printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);build();}
        else printf("God please help our poor hero.\nFINISH\n");
    }
    
    return 0;
}