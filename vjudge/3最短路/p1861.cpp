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
const int maxn = 1000 + 5;
const int maxm = 15000+5;
//自己尝试写MSP
int n,m,fa[maxn];
struct Edge{
    int u,v,w;
    bool friend operator <(Edge e1,Edge e2){
        return e1.w< e2.w;
    }
}es[maxm];
int tag[maxm];
int cnt;
//对于需要寻找边的kruscal算法写又方便
int find(int u){
    return fa[u]==u?u:fa[u]=find(fa[u]);
}


int main(){
    sf(n),sf(m);
    fr1(i,m){
        int u,v,w;
        sf(u),sf(v),sf(w);
        es[cnt].u=u,es[cnt].v=v,es[cnt].w=w;
        cnt++;
    }
    fr1(i,n) fa[i]=i;
    sort(es,es+cnt);
    int sel_e=0;
    int maxe=0;
    fr0(i,cnt){
        int u=es[i].u,v=es[i].v,w=es[i].w;
        int x=find(u),y=find(v);
        if(x!=y){
            sel_e++;
            maxe=max(maxe,w);
            tag[i]=1;
            fa[x]=y;
            if(sel_e>=n-1) break;
        }
        
    }
    pr(maxe),pr(n-1);
    fr0(i,cnt){
        if(tag[i]){
            printf("%d %d\n",es[i].u,es[i].v);
        }
    }
    


    return 0;
}