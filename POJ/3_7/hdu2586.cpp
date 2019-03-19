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
const int maxn = 4e4 + 5;
const int maxm = 8e4+5;
int head[maxn],dis[maxn],dep[maxn],dp[maxn][14];
int n,q,cnt;
struct Edge{int u,v,nxt,w;}es[maxm];
void adde(int u,int v,int w){es[cnt].u=u,es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
void dfs(int u,int father,int d,int w){
    dep[u]=d;dp[u][0]=father,dis[u]=dis[father]+w;
    for(int i=1;(1<<i)<=dep[u];i++)dp[u][i]=dp[dp[u][i-1]][i-1];
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int u=es[t].u,v=es[t].v,wei=es[t].w;
        if(v!=father){dfs(v,u,d+1,wei);}
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]>dep[v]){u=dp[u][(int)log2(dep[u]-dep[v])];}
    if(u==v)return u;
    for(int j=13;j>=0;j--){
        if(dp[u][j]!=dp[v][j]){u=dp[u][j],v=dp[v][j];}
    }
    return dp[u][0];
}



int main(){
    int t;sf(t);
    while(t--){
        scanf("%d %d",&n,&q);
        CL(head,-1),CL(dis,0),CL(dep,0),CL(dp,0);
        cnt=0;
        int u,v,w;
        fr0(i,n-1){sf(u),sf(v),sf(w);adde(u,v,w),adde(v,u,w);}
        dfs(1,0,1,0);
        fr1(i,q){
            sf(u),sf(v);int z=lca(u,v);
            printf("%d\n",dis[u]+dis[v]-2*dis[z]);
        }
    }
    
    return 0;
}