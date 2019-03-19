#include <bits/stdc++.h>
using namespace std;
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
//date:19 3月 05
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 2e4 + 5;
const int maxm = 2e5+5;
int cnt,timing,colcn,n,m;
int head[maxn],dfn[maxn],low[maxn],col[maxn];
int cut[maxn];
int cnt_cut;
struct Edge{
    int u,v,nxt;
    int isbri;//is bridge
}es[maxm];
void add(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
void tarjan(int u,int fa){//无向连通图割点
    dfn[u]=low[u]=(++timing);
    int child=0;//只需记录根结点分支
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(v!=fa&&!dfn[v]){child++;tarjan(v,u),low[u]=min(low[u],low[v]);
        if(low[v]>=dfn[u]&&fa>0){cut[u]=1;}////需要tarjna到v,u->v,v能到达的地方在u的下方
        }
        else if(v!=fa&&dfn[v]){low[u]=min(low[u],dfn[v]);}
        
        
    }
    //db(u),db(fa),db(child);
    if(fa<0&&child>=2){cut[u]=1;}//对于根节点，只需树枝边>=2,是搜索树的树枝边
}



int main(){
    sf(n),sf(m);
    CL(head,-1);
    fr1(i,m){int u,v;sf(u),sf(v);add(u,v),add(v,u);}
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i,-1);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(cut[i]) cnt++;
    }
    pr(cnt);
    for(int i=1;i<=n;i++){
        if(cut[i]) printf("%d ",i);
    }
    
    return 0;
}