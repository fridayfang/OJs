#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 2月 27
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 2e3 + 5;
const int maxm = 1e4+5;
struct Edge{
    int u,v,dis;
    bool friend operator <(Edge e1,Edge e2){
        return e1.dis<e2.dis;
    }
}es[maxm];
int n,m,fa[maxn];
int find(int u){
    return fa[u]==u?u:fa[u]=find(fa[u]);
}
int kruscal(){
    fr1(i,n) fa[i]=i;
    sort(es,es+m);
    int adde=0;
    fr0(i,m){
        int  u=es[i].u,v=es[i].v,dis=es[i].dis;
        int x=find(u), y=find(v);
        if(x!=y){
            fa[x]=y,adde++;
            if(adde>=n-1) return dis;

        }
    }
    return -1;//no find;
}



int main(){
    sf(n),sf(m);
    fr0(i,m){
        int u,v,dis;sf(u),sf(v),sf(dis);
        es[i].u=u,es[i].v=v,es[i].dis=dis;
    }
    printf("%d\n",kruscal());

    
    return 0;
}