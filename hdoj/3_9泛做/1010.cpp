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
int n,m,T;
char mpp[10][10];
int vis[10][10];
int sx,sy,dx,dy;//source dest
struct Node{
    int x,y,t;
    Node(){}
    Node(int _x,int _y,int _t):x(_x),y(_y),t(_t){}
};
Node path[10][10];
int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//
/*
//第一种写法
int dfs(cur state){
    vis[][]=1;//标记访问
    if(check()){return 1;}
    else if(尚未成功但可剪枝){vis[][]=0;return 0};
    for(扩展状态){
        if(new state is 合理的){
            dfs(new state);
        }
    }
    vis[][]=0;return 0;//return 0表示不可行需要回溯，所以不可行应该将状态恢复
}
//第二种写法
//此时调用dfs前，须将Initial state标记未vis[][]=1
int dfs(cur state){
    if(check()){return 1;}//是目标状态
    if(可剪枝){return 0;}
    for(扩展状态){
        if(合理){
            vis[][]=1;
            dfs(新状态);
            vis[][]=0;
        }
    }
    return 0;
}
*/
int dfs(int curx,int cury,int curt){
    vis[curx][cury]=1;
    if(curx==dx&&cury==dy&&curt==T) return 1;
    if(curt>T) {vis[curx][cury]=0;return 0;}
    for(int i=0;i<4;i++){
        int newx=curx+mv[i][0],newy=cury+mv[i][1],newt=curt+1;
        if(newx>=0&&newx<n&&newy>=0&&newy<m&&mpp[newx][newy]!='X'&&!vis[newx][newy]){
            if(dfs(newx,newy,newt)==1)return 1;
        }
    }
    vis[curx][cury]=0;return 0;
}
/*
int dfs(int curx,int cury,int curt){
    //db(curx),db(cury),db(curt);
    if(mpp[curx][cury]=='D'&&curt==T)return 1;
    if(curt>T||mpp[curx][cury]=='D')return 0;
    for(int i=0;i<4;i++){
        int newx=curx+mv[i][0];
        int newy=cury+mv[i][1];
        int newt=curt+1;
        if(newx>=0&&newx<n&&newy>=0&&newy<m&&mpp[newx][newy]!='X'&&!vis[newx][newy]){
            vis[newx][newy]=1;
            if(dfs(newx,newy,newt)==1){
                path[newx][newy].x=curx,path[newx][newy].y=cury,path[newx][newy].t=curt;
                return 1;}
            vis[newx][newy]=0;//恢复状态
        }
    }
    return 0;
}
*/
void help(){
    int x=dx,y=dy,t=T;
    while(path[x][y].x!=sx||path[x][y].y!=sy){
        printf("(%d,%d,%d)\n",x,y,t);
        x=path[x][y].x,y=path[x][y].y,t=path[x][y].t;

    }
}
//bfs不行要求恰好T秒,bfs求得的是每个点的最短时间
/*
int bfs(){
    queue<Node> q;
    while(!q.empty())q.pop();
    q.push(Node(sx,sy,0));
    vis[sx][sy]=1;
    while(!q.empty()){
        Node tmp=q.front();q.pop();
        if(mpp[tmp.x][tmp.y]=='D'&&tmp.t<=T)return 1;//ok
        //if(tmp.t>=T+2) return 0;
        //move
        for(int i=0;i<4;i++){
            int newx=tmp.x+mv[i][0];
            int newy=tmp.y+mv[i][1];
            int newt=tmp.t+1;
            if(newx>=0&&newx<n&&newy>=0&&newy<m&&!vis[newx][newy]&&mpp[newx][newy]!='X'){
                vis[newx][newy]=1;
                q.push(Node(newx,newy,newt));
            }

        }
    }
    return 0;

}
*/



int main(){
    while(scanf("%d %d %d",&n,&m,&T)&&n){
        CL(vis,0);
        fr0(i,n){
            scanf("%s",mpp[i]);
            //printf("%s\n",mpp[i]);
            for(int j=0;j<m;j++){
                if(mpp[i][j]=='S'){sx=i,sy=j;}
                if(mpp[i][j]=='D'){dx=i,dy=j;}
            }
        }
        /*
        for(int i=0;i<4;i++){
            printf("%d %d\n",mv[i][0],mv[i][1]);
        }
        */
        if((abs(dx+dy-sx-sy+T))%2!=0)printf("NO\n");
        else {
            vis[sx][sy]=1;
            int ans=dfs(sx,sy,0);
            if(ans==1){printf("YES\n");}
            else printf("NO\n");
        }


    }
    
    return 0;
}