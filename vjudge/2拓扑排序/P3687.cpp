#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
using namespace std;
//author:fridayfang
//date:19 2月 24
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 200 + 5;
const int maxm = 40000+5;
//topo经典题目
int head[maxn],deg[maxn],srt[maxn],out[maxn];
int n,m;
int cnt;
struct Edge{
    int u,v,nxt;
}es[maxm];
void add(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u];
    head[u]=cnt,deg[v]++,cnt++;
}
void build(){
    sf(n),sf(m);
    CL(head,-1),CL(deg,0),CL(srt,0);
    cnt=0;
    fr0(i,m){
        int u,v;
        sf(u),sf(v);
        add(v,u);
    }
}
/*struct cmp2
{
    bool operator()(int a, int b) {
        return a < b;
    }
};
*/
void topo(){
    priority_queue<int> q;
    int cnt=n;
    fr1(i,n){
        if(deg[i]==0)q.push(i);
    }
    while(!q.empty()){
        int tmp=q.top();
        q.pop();
        srt[tmp]=(cnt--);//label tmp weight cnt--
        //out[cnt+1]=tmp;
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int u=es[t].u,v=es[t].v;
            if((--deg[v])==0) q.push(v);
        }
    }
    if(cnt>0) printf("-1");
    else{
        for(int i=1;i<=n;i++){
            printf("%d ",srt[i]);
        }
    }
    printf("\n");

}


int main(){
    int t;sf(t);
    while(t--){
        build();
        topo();
    }
    return 0;
}