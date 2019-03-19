#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
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

int head[220];
struct Edge{int u,v,nxt,w;}es[11000];
int cnt;
void adde(int u,int v,int w){
    //db(u),db(v),db(w);
    es[cnt].u=u,es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
int n,m,s,v;
struct Point{
    float x,y;
}p[220];
int dep[maxn];
int bfs(int s,int d,int des){
    CL(dep,-1);queue<int> q;dep[s]=d,q.push(s);
    while(!q.empty()){
        int tmp=q.front();q.pop();
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int v=es[t].v;
            if(dep[v]==-1&&es[t].w>0){
                dep[v]=dep[tmp]+1;q.push(v);
            }
        }
    }
    if(dep[des]<0) return 0;//false;
    else return 1;

}
int dinic(int cur,int flow,int des){//flow是流入cur的流量
    if(cur==des||flow<=0)return flow;
    int res=0;//记录多路增广的
    for(int t=head[cur];flow&&t!=-1;t=es[t].nxt){
        int v=es[t].v,cap=es[t].w;
        if(dep[v]==dep[cur]+1&&es[t].w>0){
            int f=dinic(v,min(cap,flow),des);
            es[t].w-=f,es[t^1].w+=f;
            flow-=f;
            res+=f;
        }
    }
    if(res==0) dep[cur]=-2;
    return res;

}

int main(){
    while(~scanf("%d %d %d %d",&n,&m,&s,&v)){
        CL(head,-1),cnt=0;
        for(int i=1;i<=(n+m);i++){
            scanf("%f %f",&p[i].x,&p[i].y);
        }
        for(int i=1;i<=n;i++){
            for(int j=n+1;j<=n+m;j++){
                float dis=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
                if(dis-(float)(v*s)<esp){
                    //add edge
                    adde(i,j,1);
                    adde(j,i,0);
                }
            }
        }
        //
        for(int i=1;i<=n;i++){
            adde(0,i,1),adde(i,0,0);
        }
        for(int i=n+1;i<=n+m;i++){
            adde(i,n+m+1,1),adde(n+m+1,i,0);
        }
        int ans=0;
        while(bfs(0,1,n+m+1)){
            ans+=dinic(0,inf,n+m+1);
        }
        pr(n-ans);

    }
    
    return 0;
}