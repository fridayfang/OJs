#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 2月 28
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 2e3 + 5;
const int maxm = 2e5+5;
struct Edge{int v,nxt,cap;}es[maxm];
int head[maxn],dep[maxn],cnt,n,m,src,des;
void add(int u,int v,int cap){//printf("db %d-> %d %d\n",u,v,cap);
    es[cnt].v=v,es[cnt].cap=cap,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
int bfs(){
    queue<int> q;
    CL(dep,-1);dep[src]=1;q.push(src);
    while(!q.empty()){
        int tmp=q.front();q.pop();
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int v=es[t].v,cap=es[t].cap;
            if(dep[v]==-1&&cap>0){
                //printf("db dep[%d] %d\n",v,dep[v]);
                dep[v]=dep[tmp]+1;
                q.push(v);
                if(v==des) return 1;
                //printf("db dep[%d] %d\n",v,dep[v]);
            }
        }
    }
    for(int i=0;i<=n+m+2;i++){
        printf("dep %d %d\n",i,dep[i]);
    }
    return dep[des]>-1;
}
int dfs(int s,int flow){//flow是流进s的流量
    if(s==des) return flow;
    int res=0;
    for(int t=head[s];flow&&t!=-1;t=es[t].nxt){
        int v=es[t].v,cap=es[t].cap;
        if(dep[v]==dep[s]+1){
            int f=dfs(v,min(flow,cap));
            res+=f,es[t].cap-=f,es[t^1].cap+=f,flow-=f;
        }
    }
    if(!res) dep[s]=-2;
    return res;
}
int main(){
    sf(m),sf(n);//m pigs
    CL(head,-1);
    int sum=0;
    fr1(i,m){int x;sf(x);sum+=x;add(1,i+1,x),add(i+1,1,0);}
    add(0,1,sum),add(1,0,0);
    fr1(j,n){
        //n customers
        int a;sf(a);
        fr1(k,a){int x;sf(x);add(x+1,j+m+1,inf),add(j+m+1,x+1,0);}
        int b;sf(b);
        add(j+m+1,n+m+2,b),add(n+m+2,j+m+1,0);
    }
    //bild ok
    src=1,des=n+m+2;
    int ans=0;
    while(bfs()){
        int addf;
        if(addf=dfs(1,inf)) ans+=addf;
        db(addf);
    }
    printf("%d\n",ans);


    
    return 0;
}