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
const int maxn = 1e2 + 5;
const int maxm = 1e4+5;
int head[maxn],dfn[maxn],low[maxn],col[maxn],cut[maxn];
int n,m,colcn,cnt,timing;
struct Edge{int u,v,nxt;}es[maxm];
void adde(int u,int v){//db(u),db(v);
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
void tarjan(int u,int fa){
    dfn[u]=low[u]=(++timing);
    int child=0;
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(!dfn[v]){
            child++;
            tarjan(v,u);low[u]=min(low[v],low[u]);
            if(low[v]>=dfn[u]&&u!=fa){cut[u]=1;}//非根节点
        }
        else if(v!=fa)low[u]=min(low[u],dfn[v]);//无向图
    }
    if(fa==u&&child>=2) cut[u]=1;//根节点

}

char s[maxn<<1];

int main(){
    while(scanf("%d",&n)&&n){
        CL(head,-1),CL(dfn,0),CL(low,0),CL(cut,0);
        cnt=timing=0;
        int u,v;
        while(sf(u)&&u){
            while(getchar()!='\n'){
                sf(v);adde(u,v),adde(v,u);
            }
        }
        //
        for(int i=1;i<=n;i++){if(!dfn[i])tarjan(i,i);}
        int count=0;
        for(int i=1;i<=n;i++){if(cut[i])count++;}
        pr(count);
    }
    
    return 0;
}