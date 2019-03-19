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
const int maxm = 5e4+5;
int n,m,cnt;
int head[maxn];
int label[maxn];//强连通分量缩点，重新编号
stack<int> st;//for tarjna
int dfn[maxn],low[maxn],ins[maxn];//for tarjan
int time,tagsum,deg[maxn];
int ndeg[maxn],cunt[maxn];
struct Edge{
    int v,nxt;
}es[maxm];
void add(int u,int v){
    es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
    deg[v]++;
    //db(u),db(v);
}
void tarjan(int u){
    dfn[u]=low[u]=(++time);
    st.push(u),ins[u]=1;
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(!dfn[v]){//未访问
            tarjan(v);low[u]=min(low[u],low[v]);//树枝边
        }
        else if(ins[v]){//访问过且在栈中，后向边or 横叉边
            low[u]=min(low[u],dfn[v]);
        }

    }
    //db(u),db(dfn[u]),db(low[u]);
    if(dfn[u]==low[u]){//强连通分量
        //db(u);
        int j=st.top();
        //db(j);
        ins[j]=0,label[j]=(++tagsum);
        cunt[tagsum]++;
        st.pop();
        while(j!=u){
            j=st.top(),ins[j]=0,label[j]=tagsum,st.pop();
            cunt[tagsum]++;
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    sf(n),sf(m);
    CL(head,-1);
    fr1(i,m){int u,v;sf(u),sf(v);add(v,u);}
    //图可能1不连通
    for(int i=1;i<=n;i++){
        if(!dfn[i]){tarjan(i);}
    }
    //
    int sum0=0,tmplabel=inf;
    for(int i=1;i<=n;i++){//重新遍历边，求得缩点后的入度
        for(int t=head[i];t!=-1;t=es[t].nxt){
            int v=es[t].v;
            if(label[v]!=label[i]) ndeg[label[v]]++;//统计入度
        }
    }
    int num=0,nlabel=0;
    for(int i=1;i<=tagsum;i++){
        if(ndeg[i]==0){num++,nlabel=i;}
    }
    //db(num);
    if(num==1)pr(cunt[nlabel]);
    else printf("0\n");

    return 0;
}
