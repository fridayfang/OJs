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
const int maxn = 1e4 + 5;
const int maxm = 1e5+5;
int head[maxn],ins[maxn],col[maxn],dfn[maxn],low[maxn];
int n,m,colcn,cnt,timing;
stack<int> st;
struct Edge{int u,v,nxt;}es[maxm];
void add(int u,int v){es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
void tarjan(int u){
    dfn[u]=low[u]=(++timing);
    st.push(u),ins[u]=1;
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
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


int main(){
    while(scanf("%d %d",&n,&m)&&n){
        CL(head,-1),CL(ins,0),CL(dfn,0),CL(low,0),CL(col,0);
        colcn=0,cnt=0,timing=0;
        fr1(i,m){int u,v;sf(u),sf(v);add(u,v);}
        bool sol=false;
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i);if(colcn>1){
                    printf("No\n");
                    sol=true;
                    break;
                }
            }
        }
        if(sol) continue;
        else printf("Yes\n");
        
    }
    
    return 0;
}