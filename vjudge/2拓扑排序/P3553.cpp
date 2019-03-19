#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 2月 25
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 50010;
const int maxm = 500100;
//cj-dj  cj-1+pj-dj 所以pj-dj越小的应该放在后面,
int deg[maxn],n,m,head[maxn],cnt;
struct node{
    int p,d;
    int index;
}nod[maxn];
bool operator < (node n1,node n2){
    return (n1.p-n1.d)<(n2.p-n2.d);
}
struct Edge{
    int u,v,nxt;
}es[maxm];
void add(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u];
    head[u]=cnt,deg[v]++,cnt++;
}
void topo(){
    priority_queue<node> q;
    for(int i=1;i<=n;i++){
        if(!deg[i]) q.push(nod[i]);
    }
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        printf("%d\n",tmp.index);
        int t=tmp.index;
        for(int k=head[t];k!=-1;k=es[k].nxt){
            int v=es[k].v;
            if(!(--deg[v])){
                q.push(nod[v]);
            }
        }

    }

}
int main(){
    CL(head,-1),CL(deg,0);
    sf(n);
    fr1(i,n){
        sf(nod[i].p),sf(nod[i].d);
        nod[i].index=i;
    }
    sf(m);
    fr1(j,m){
        int u,v;sf(u),sf(v);
        add(u,v);
    }
    topo();
    return 0;

}
