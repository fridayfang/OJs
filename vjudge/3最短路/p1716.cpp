#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 2月 27
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e4 + 5;
const int maxm = 1e7+5;
int cnt;
int head[maxn],vis[maxn],dis[maxn],ct[maxn];//记录每个点进入队列次数
struct Edge{
    int v,nxt,w;
}es[maxm];
void add(int u,int v,int w){
    es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u];
    head[u]=cnt,cnt++;
}
int spfa(int r,int d){//d 是目的节点
    //最长路径
    //printf("db %d %d %d\n",r,d,n);
    CL(dis,128);//有负权，dis[]求最长路应清-inf
    //printf("db %d\n",dis[128]);
    dis[r]=0;
    queue<int> q;q.push(r);
    vis[r]=1;//表示进入队列
    while(!q.empty()){
        int tmp=q.front();q.pop();
        vis[tmp]=0;//表示出队列
        //printf("db %d dis: %d\n",tmp,dis[tmp]);
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            //printf("db u->v %d->%d\n",tmp,es[t].v);
            int v=es[t].v,w=es[t].w;
            if(dis[tmp]+w>dis[v]){
                dis[v]=dis[tmp]+w;
                if(vis[v]) continue;
                q.push(v);vis[v]=1;
                //if(ct[v]>=n) return -1;//表示有环
            }
        }

    }
    return dis[d];
    
}
int main(){
    int t;sf(t);
    int minv=inf,maxv=0;
    CL(head,-1);
    int r=0;
    while(t--){
        int x,y;sf(x),sf(y);
        add(x,y+1,2);
        r=max(y,r);
    }
    r++;
    for(int i=0;i<r;i++){
        add(i,i+1,0);
        add(i+1,i,-1);
    }
    int ans=spfa(0,r);
    /*
    while(t--){
        int a,b;
        sf(a),sf(b);
        add(a,b+1,2);
        maxv=b>maxv?b:maxv;
        minv=a<minv?a:minv;
    }
    for(int i=minv;i<=maxv;i++){
        add(i,i+1,0);
        add(i+1,i,-1);
    }
    */
    //int ans=spfa(minv,maxv+1,maxv-minv+1);
    printf("%d\n",ans);
    
    return 0;
}