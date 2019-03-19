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
const int maxn = 1e4 + 5;
const int maxm = 2e4+5;
int dep[maxn],dp[maxn][16];//初始化清0,千万不要越界，否则有很多bugs
int head[maxn],nroot[maxn];
int cnt,n,m;
struct Edge{int u,v,nxt;}es[maxm];
void adde(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
void dfs(int u,int fa,int de){
    dep[u]=de;
    dp[u][0]=fa;
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int u=es[t].u,v=es[t].v;
        if(v!=fa){dfs(v,u,de+1);}
    }
}
//利用dep[]数组处理倍增数组
void build(){
    for(int j=1;j<=15;j++){
        for(int i=1;i<=n;i++){
            
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
}
int get_lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]>dep[v]){u=dp[u][(int)log2(dep[u]-dep[v])];}
    //now dep[u]==dep[v]
    if(u==v) return u;
    for(int j=15;j>=0;j--){
        if(dp[u][j]==dp[v][j]) continue;
        else{
            //db(u),db(v),db(j);
            u=dp[u][j],v=dp[v][j];
            
        }
    }
    return dp[u][0];

}
int main(){
    int t;sf(t);
    while(t--){
        CL(dep,0),CL(dp,0),CL(head,-1),CL(nroot,0),cnt=0;
        sf(n);int u,v,root=0;
        fr0(i,n-1){sf(u),sf(v);adde(u,v),nroot[v]=1;}
        fr1(i,n){if(!nroot[i]){root=i;break;}}        
        dfs(root,0,1);
        build();
        scanf("%d %d",&u,&v);
            int ans=get_lca(u,v);
            pr(ans);   
           
    }
    
    return 0;
}