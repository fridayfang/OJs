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
//date:19 3月 04
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 100 + 5;
const int maxm = 10000+5;
int head[maxn],dfn[maxn],low[maxn],col[maxn],ins[maxn];
int n,cnt,timing,colcn;
int in[maxn],out[maxn];//缩点后的deg
int scgcnt;//统计强连通分量数目
stack<int> st;
struct Edge{int u,v,nxt;}es[maxm];
void adde(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
void tarjan(int u){
    dfn[u]=low[u]=(++timing);st.push(u),ins[u]=1;
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(!dfn[v]){tarjan(v);low[u]=min(low[u],low[v]);}
        else if(ins[v]){low[u]=min(low[u],dfn[v]);}
    }
    if(dfn[u]==low[u]){
        scgcnt++;
        
        int j=st.top();ins[j]=0,col[j]=(++colcn),st.pop();
        ///db(u),db(colcn);
        while(j!=u){
            j=st.top(),st.pop(),ins[j]=0,col[j]=colcn;
        }
    }
}
int maxin,maxout;
void calc(){
    for(int i=0;i<cnt;i++){
        int u=es[i].u,v=es[i].v;
        int x=col[u],y=col[v];
        //if(x!=y) {db(u),db(v),db(x),db(y);}
        if(x!=y){out[x]++,in[y]++;}
    }
    for(int i=1;i<=colcn;i++){
        if(in[i]==0) maxin++;
        if(out[i]==0) maxout++;
    }

}

int main(){
    sf(n);CL(head,-1);
    fr1(i,n){
        int v;
        while(sf(v)&&v){adde(i,v);}
    }
    for(int i=1;i<=n;i++){if(!dfn[i])tarjan(i);}
    calc();
    int ans_a=0;
    for(int i=1;i<=colcn;i++){
        if(in[i]==0) ans_a++;
    }
    pr(ans_a);
    int ans_b=(scgcnt==1)?0:max(maxin,maxout);//特判本身就是强连通分量情况
    pr(ans_b);
    
    return 0;
}