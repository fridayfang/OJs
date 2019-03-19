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
const int maxn = 1e5 + 5;
const int maxm = 1e5+5;
ll pw[maxn],ew[maxn];
int head[maxn],dep[maxn],dp[maxn][20],a[maxn];//点权
int n,ops,cnt;
struct Edge{int u,v,w,nxt;}es[maxm];
void adde(int u,int v){es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
void dfs(int u,int father,int d,int w){
    dep[u]=d,dp[u][0]=father,pw[u]+=pw[father],es[u]+=w;
    for(int i=1;(1<<i)<=u;i++)dp[u][i]=dp[dp[u][i-1]][i-1];
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int u=es[t].u,v=es[t].v,w=es[t].w;
        if(v!=father)dfs(v,u,d+1,w);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]>dep[v]){u=dp[dp[u][i-1]][i-1];}
    if(u==v)return u;
    for(int j=19;j>=0;j--){
        if(dp[u][j]!=dp[v][j]){u=dp[u][j],v=dp[v][j];}
    }
    return dp[u][0];
}
char op[10];

int main(){
    int t;sf(t);
    while(t--){
        CL(head,-1),CL(dep,0),CL(dp,0),CL(pw,0),CL(ew,0);
        cnt=0;
        sf(n),sf(ops);
        fr1(i,n-1){int u,v,w;sf(u),sf(v),sf(w);adde(u,v),adde(v,u);}
        fr1(i,q){
            scanf("%s",op);
        }
    }
    return 0;
}