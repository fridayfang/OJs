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
const int maxn = 1e4 + 5;
const int maxm =5e4+5;
struct Edge{
    int v,nxt;
}es[maxm];
int head[maxn],dfn[maxn],low[maxn],ins[maxn],n,m,cnt,timing;
stack<int> st;
int ans;
void adde(int u,int v){es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
void tarjan(int u){
    dfn[u]=low[u]=(++timing),ins[u]=1,st.push(u);
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(!dfn[v]){tarjan(v);low[u]=min(low[u],low[v]);}//搜索边
        else if(ins[v]){low[u]=min(low[u],dfn[v]);}//后向边，横叉边
    }
    if(dfn[u]==low[u]){
        int cnt_size=0;
        int j=st.top();st.pop();ins[j]=0,cnt_size++;
        while(j!=u){
            j=st.top(),st.pop(),ins[j]=0;cnt_size++;
        }
        if(cnt_size>=2) ans++;
    }
}



int main(){
    CL(head,-1);
    sf(n),sf(m);fr1(i,m){int u,v;sf(u),sf(v);adde(u,v);}
    fr1(i,n){
        if(!dfn[i]) tarjan(i);
    }
    pr(ans);

    
    return 0;
}