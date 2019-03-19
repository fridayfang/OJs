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
//date:19 3月 04
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 5e4 + 5;
const int maxm = 1e5+5;
int head[maxn],dfn[maxn],low[maxn],col[maxn],ins[maxn];
int n,m,timing,colcn,cnt,cnt2;
stack<int> st;
struct Edge{int u,v,nxt,w;}es[maxm],es2[maxm];
void add1(int u,int v,int c){
    es[cnt].u=u,es[cnt].v=v,es[cnt].w=c,es[cnt].nxt=head[u];
    head[u]=cnt,cnt++;
}
void add2(int u,int v,int c){
    //db(u),db(v),db(c);
    es2[cnt2].u=u,es2[cnt2].v=v,es2[cnt2].w=c;
    cnt2++;
}
bool cmp(Edge e1,Edge e2){
    return e1.w<e2.w;
}
void tarjan(int u){
    dfn[u]=low[u]=(++timing);st.push(u),ins[u]=1;
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v,w=es[t].w;
        if(!dfn[v]){tarjan(v);low[u]=min(low[u],low[v]);}
        else if(ins[v]){low[u]=min(low[u],dfn[v]);}
    }
    if(dfn[u]==low[u]){
        int j;colcn++;
        do{
            j=st.top(),st.pop(),ins[j]=0,col[j]=colcn;
        }while(j!=u);
    }
}
//重新建图
int fa[maxn];
int find(int u){return fa[u]==u?fa[u]:fa[u]=find(fa[u]);}
//
int dis[maxn];//记录到所有到i的边的最小值
ll rebuild(){
    fr1(i,colcn){fa[i]=i;}
    for(int i=0;i<cnt;i++){
        int x=col[es[i].u],y=col[es[i].v],c=es[i].w;
        if(x!=y){add2(x,y,c);}
    }
    //建好新图
    sort(es2,es2+cnt2,cmp);
    CL(dis,0x3f);
    int ecnt=0;//the num of edge selected
    ll ans=0;
    for(int i=0;i<cnt2;i++){
        int u=es2[i].u,v=es2[i].v,w=es2[i].w;
        if(dis[v]==inf) dis[v]=w;    
    }
    for(int i=1;i<=colcn;i++){
        //db(i),db(dis[i]);
        if(dis[i]<inf) ans+=dis[i];//入度为0的点不要选
    }
    return ans;
}

int main(){
    while(~scanf("%d %d",&n,&m)){
        CL(head,-1),CL(dfn,0),CL(low,0),CL(col,0),CL(ins,0);
        timing=colcn=cnt=cnt2=0;
        for(int i=1;i<=m;i++){int u,v,c;sf(u),sf(v),sf(c);add1(u,v,c);}
        for(int i=0;i<n;i++){
            if(!dfn[i])tarjan(i);
        }
        ll ans=rebuild();
        printf("%lld\n",ans);
    }
    
    return 0;
}