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
//date:19 3月 11
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 1e6+5;
struct Edge{
    int u,v,w;
}es[maxm];
bool cmp(Edge e1,Edge e2){return e1.w>e2.w;}
int cnt,n,m;
void adde(int u,int v,int w){es[cnt].u=u,es[cnt].v=v,es[cnt].w=w,cnt++;}
int fa[maxn];
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
struct edge{int u,v,w,nxt;}egs[10020];//maximum spanning tree
int cnt2;
int head[maxn];
void adde2(int u,int v,int w){//db(u),db(v),db(w);
    egs[cnt2].u=u,egs[cnt2].v=v,egs[cnt2].w=w,egs[cnt2].nxt=head[u],head[u]=cnt2,cnt2++;}
//
int weight[maxn];
void dfs(int cur,int fa,int wei){
    //db(cur),db(fa),db(wei);
    weight[cur]=min(weight[fa],wei);
    for(int t=head[cur];t!=-1;t=egs[t].nxt){
        int v=egs[t].v,w=egs[t].w;
        if(v!=fa){
            dfs(v,cur,w);
        }
    }
}

int main(){
    int t;sf(t);
    int cas=0;
    while(t--){
        cas++;
        sf(n),sf(m);CL(head,-1);
        cnt=0;
        for(int i=1;i<=m;i++){
            int u,v,w;sf(u),sf(v),sf(w);adde(u,v,w);
        }
        sort(es,es+cnt,cmp);

        int sel=0,maxw=inf;
        cnt2=0;
        fr1(i,n)fa[i]=i;
        for(int i=0;i<cnt;i++){
            if(sel==n-1) break;
            int u=es[i].u,v=es[i].v,w=es[i].w;
            int x=find(u),y=find(v);
            if(x!=y){
                fa[x]=y;sel++;
                adde2(u,v,w),adde2(v,u,w);
            }
            
        }
        weight[0]=inf;
        dfs(1,0,inf);
        printf("Scenario #%d:\n%d\n\n",cas,weight[n]);

    }
    
    return 0;
}