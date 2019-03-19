#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
#define ll long long
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
int head[maxn],dp[maxn][17],path[maxn][17],dep[maxn];
int cnt,n,m;
struct Edge{int u,v,w,nxt;}es[maxm];
void adde(int u,int v,int w){
    es[cnt].u=u,es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
void dfs(int u,int father,int d,int w){
    dep[u]=d;dp[u][0]=father,path[u][0]=w;
    for(int i=1;(1<<i)<=dep[u];i++){
        path[u][i]=path[u][i-1]+path[dp[u][i-1]][i-1];
        dp[u][i]=dp[dp[u][i-1]][i-1];        
    }
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int u=es[t].u,v=es[t].v,w=es[t].w;
        if(v!=father){dfs(v,u,d+1,w);}
    }
}
int lca(int u,int v){

    int len=0;
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]>dep[v]){
        len+=path[u][(int)log2(dep[u]-dep[v])];
        u=dp[u][(int)log2(dep[u]-dep[v])];
    }
    if(u==v) return len;
    for(int j=16;j>=0;j--){
        if(dp[u][j]!=dp[v][j]){
            len+=(path[u][j]+path[v][j]);
            u=dp[u][j],v=dp[v][j];
        }
    }
    //db(u),db(v);
    len+=(path[u][0]+path[v][0]);
    return len;
}

char s[3];

int main(){
    sf(n),sf(m);
    CL(head,-1);
    fr1(i,m){
        int u,v,w;
        sf(u),sf(v),sf(w),scanf("%s",s);
        adde(u,v,w),adde(v,u,w);
    }
    dfs(1,0,1,0);
    int q;sf(q);
    fr1(i,q){
        int u,v;sf(u),sf(v);
        pr(lca(u,v));
    }

    
    return 0;
}