#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
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
//date:19 3月 07
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 2e4+5;
int n,m,q,cnt;
int head[maxn],fa[maxn],dp[maxn][15],path[maxn][15],dep[maxn],dis[maxn];//并查集
struct Edge{int u,v,nxt,w;}es[maxm];

int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
void adde(int u,int v,int w){
    int x=find(u), y=find(v);
    if(x!=y)fa[x]=y;
    es[cnt].u=u,es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
void dfs(int u,int father,int d,int w){
    dep[u]=d;dp[u][0]=father,path[u][0]=w;
    dis[u]=dis[father]+w;
    for(int i=1;(1<<i<=dep[u]);i++){
        path[u][i]=path[u][i-1]+path[dp[u][i-1]][i-1];
        dp[u][i]=dp[dp[u][i-1]][i-1];
    }
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int u=es[t].u,v=es[t].v,wei=es[t].w;
        if(v!=father){dfs(v,u,d+1,wei);}
    }
}
int lca(int u,int v){
    int len=0;
    if(dep[u]<dep[v])swap(u,v);
    //db(dep[u]),db(dep[v]);
    while(dep[u]>dep[v]){
        len+=path[u][(int)log2(dep[u]-dep[v])];
        u=dp[u][(int)log2(dep[u]-dep[v])];}
    //if(u==v) return len;
    if(u==v) return u;
    for(int j=14;j>=0;j--){
        if(dp[u][j]!=dp[v][j]){
            len+=(path[u][j]+path[v][j]);
            u=dp[u][j],v=dp[v][j];
        }
    }
    //db(u),db(v),db(len);
    //len+=(path[u][0]+path[v][0]);
    //return len;
    return dp[u][0];
}
int main(){
    while(scanf("%d %d %d",&n,&m,&q)!=EOF){
        CL(head,-1),CL(dp,0),CL(path,0),CL(dep,0),CL(dis,0);
        fr1(i,n)fa[i]=i;
        cnt=0;
        int u,v,w;
        fr1(i,m){sf(u),sf(v),sf(w);adde(u,v,w),adde(v,u,w);}
        fr1(i,n){if(!dep[i])dfs(i,0,1,0);}
        fr1(i,q){
            sf(u),sf(v);
            int x=find(u),y=find(v);
            //db(u),db(v),db(x),db(y);
            if(x!=y)printf("Not connected\n");
            else{
                int z=lca(u,v);
                printf("%d\n",dis[u]+dis[v]-2*dis[z]);
            }
        }
    }
    
    return 0;
}