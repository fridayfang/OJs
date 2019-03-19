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
//date:19 3月 05
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 2e3 + 5;
const int maxm = 2e5+5;
vector<int> g[maxn];//原始图
int cnt,timing,colcn,n;
int head[maxn],dfn[maxn],col[maxn],low[maxn];
int k2g[maxn];//开始对应关系
struct Edge{
    int u,v,nxt;
}es[maxm];
void adde(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
stack<int> st;
int ins[maxn],sum[maxn];
void tarjan(int u){
    dfn[u]=low[u]=(++timing),st.push(u),ins[u]=1;
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(!dfn[v]){tarjan(v);low[u]=min(low[u],low[v]);}
        else if(ins[v]){low[u]=min(low[u],dfn[v]);}
    }
    if(dfn[u]==low[u]){
        int j;colcn++;
        do{
            j=st.top(),st.pop(),ins[j]=0,col[j]=colcn,sum[colcn]++;
        }while(j!=u);
    }

}
void rebuild(){
    CL(head,-1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            int u=i,v=g[i][j];
            if(k2g[u]!=v)adde(k2g[u],v);
        }
    }
    //
    for(int i=1;i<=n;i++){if(!dfn[i])tarjan(i);}
    for(int i=1;i<=n;i++){
        //i:王子 u:一个匹配中对应的公主
        //
        int u=k2g[i],color=col[u],sumgirl=sum[color];
        //u代表的强连通分量
        int store[maxn];
        int anscnt=0;
        for(int k=0;k<g[i].size();k++){//只能选你能选的
            int v=g[i][k];if(col[v]==color){
                store[anscnt]=v,anscnt++;
            }
        }
        sort(store,store+anscnt);
        printf("%d",anscnt);
        for(int i=0;i<anscnt;i++){printf(" %d",store[i]);}
        printf("\n");
    }
}


int main(){
    sf(n);fr1(i,n){
        int k;sf(k);
        fr1(j,k){int v;sf(v);g[i].push_back(v);}
    }
    for(int i=1;i<=n;i++){sf(k2g[i]);}
    rebuild();

    
    return 0;
}