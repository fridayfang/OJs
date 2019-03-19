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
const int maxn = 2e5 + 5;
const int maxm = 4e5+5;
int head[maxn],fa[maxn];
int dp[maxn][20],dep[maxn];
int heavy[maxn][20];//维护向上最重的边
int cnt,n,m;
struct Edge{
    int u,v,nxt,w;
    Edge(){}
    Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w),nxt(-1){}
}es[maxm],es2[maxm],es3[maxm];
void adde(int u,int v,int w){
    es[cnt].u=u,es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
//es2 kruscal算法
bool cmp(Edge e1,Edge e2){return e1.w<e2.w;}
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
ll kruscal(){
    fr1(i,n)fa[i]=i;
    sort(es2,es2+m,cmp);
    int cnte=0;
    ll len=0;
    for(int i=0;i<m;i++){
        int u=es2[i].u,v=es2[i].v,w=es2[i].w;
        int x=find(u),y=find(v);
        if(x!=y){
            cnte++;
            fa[x]=y;len+=w;
            adde(u,v,w),adde(v,u,w);
        }
        if(cnte>=n-1)break;
    }
    return len;
    //build a tree
}
void dfs(int u,int father,int d,int wei){
    dep[u]=d;dp[u][0]=father,heavy[u][0]=wei;
    for(int i=1;(1<<i)<=dep[u];i++)dp[u][i]=dp[dp[u][i-1]][i-1];
    for(int i=1;(1<<i)<=dep[u];i++)heavy[u][i]=max(heavy[u][i-1],heavy[dp[u][i-1]][i-1]);
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int u=es[t].u,v=es[t].v,w=es[t].w;
        if(v!=father)dfs(v,u,d+1,w);
    }
}
int lca(int u,int v){//u-lac(u,v)-v这条链上的最大权重
    int maxlen=0;
    if(dep[u]<dep[v])swap(u,v);
    while(dep[u]>dep[v]){
        maxlen=max(maxlen,heavy[u][(int)log2(dep[u]-dep[v])]);
        u=dp[u][(int)log2(dep[u]-dep[v])];
        }
    //dep[u]=dep[v]
    if(u==v) return maxlen;
    for(int j=18;j>=0;j--){
        if(dp[u][j]!=dp[v][j]){
            maxlen=max(maxlen,max(heavy[u][j],heavy[v][j]));
            u=dp[u][j],v=dp[v][j];
        }
    }
    maxlen=max(maxlen,max(heavy[u][0],heavy[v][0]));
    return maxlen;
}



int main(){
    sf(n),sf(m);
    CL(head,-1);
    fr0(i,m){
        int u,v,w;sf(u),sf(v),sf(w);es2[i]=Edge(u,v,w),es3[i]=Edge(u,v,w);
    }
    ll minlen=kruscal();
    int root=1;//根节点
    dfs(root,0,1,0);
    //db(minlen);
    fr0(i,m){
        int u=es3[i].u,v=es3[i].v,w=es3[i].w;
        int maxlen=lca(u,v);
        //db(maxlen),db(w);
        ll ans=minlen-maxlen+w;
        printf("%lld\n",ans);
    }


    
    return 0;
}