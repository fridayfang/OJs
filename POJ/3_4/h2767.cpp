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
const int maxn = 2e4 + 5;
const int maxm = 5e4+5;
int head[maxn],dfn[maxn],low[maxn],col[maxn],ins[maxn];
int in[maxn],out[maxn];
int n,m,colcn,timing ,cnt;
stack<int> st;
struct Edge{int u,v,nxt;}es[maxm];
void adde(int u,int v){es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
void tarjan(int u){
     dfn[u]=low[u]=(++timing);st.push(u),ins[u]=1;
     for(int t=head[u];t!=-1;t=es[t].nxt){
         int v=es[t].v;
         if(!dfn[v]){tarjan(v);low[u]=min(low[v],low[u]);}
         else if(ins[v]){low[u]=min(low[u],dfn[v]);}
     }
     if(dfn[u]==low[u]){
         colcn++;int j;
         do{
             j=st.top(),st.pop(),ins[j]=0,col[j]=colcn;
         }while(j!=u);
     }
}
int calc(){
    for(int i=0;i<cnt;i++){
        int x=col[es[i].u],y=col[es[i].v];
        if(x!=y){in[y]++,out[x]++;}
    }
    int inc=0,outc=0;
    for(int i=1;i<=colcn;i++){
        if(in[i]==0) inc++;
        if(out[i]==0) outc++;
    }
    //db(inc),db(outc);
    return max(inc,outc);
}



int main(){
    int t;sf(t);
    while(t--){
        scanf("%d %d",&n,&m);
        CL(head,-1),CL(ins,0),CL(dfn,0),CL(low,0),CL(col,0),CL(in,0),CL(out,0);
        cnt=timing=colcn=0;
        fr1(i,m){int u,v;sf(u),sf(v);adde(u,v);}
        for(int i=1;i<=n;i++){if(!dfn[i])tarjan(i);}
        int ans=(colcn<=1)?0:calc();
        printf("%d\n",ans);
    }
    
    return 0;
}