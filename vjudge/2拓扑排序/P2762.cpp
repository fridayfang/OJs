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
const int maxn = 1e3 + 5;
const int maxm = 6010;
struct Edge{
    int u,v,nxt;
}es[maxm];
int n,m;
int head[maxn],cnt,deg[maxn];
void add(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u];
    head[u]=cnt,deg[v]++;
    cnt++;
}
bool topo(){
    queue<int> q;
    fr1(i,n){if(deg[i]==0) q.push(i);}
    //db(q.size());
    while(!q.empty()){
        if(q.size()>=2) return false;
        int tmp=q.front();
        q.pop();
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int u=es[t].u,v=es[t].v;
            if((--deg[v])==0) q.push(v);
        }
    }
    return true;
    
}



int main(){
    int t;
    sf(t);
    while(t--){
        sf(n),sf(m);
        CL(head,-1);
        CL(deg,0);
        cnt=0;
        fr1(i,m){
            int u,v;
            sf(u),sf(v);
            add(u,v);
        }
        if(topo()) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}