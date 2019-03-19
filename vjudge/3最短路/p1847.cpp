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
const int maxn = 100 + 5;
const int maxm = 100*100+5;
int n,a,b,cnt;
int head[maxn],dis[maxn];
struct Edge{
    int v,nxt,w;
    Edge(){}
    Edge(int v_ ,int nxt_ ,int w_):v(v_),nxt(nxt_),w(w_){}
}es[maxm];
void add(int u,int v,int w){
    es[cnt].v=v,es[cnt].w=w;
    es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
struct Node{
    int idx,di;
    Node(int idx_ ,int dis_):idx(idx_),di(dis_){}
    bool friend operator < (const Node& n1,const Node& n2){
        return n1.di>n2.di;
    }
};
int dij(int r){
    CL(dis,0x3f);
    priority_queue<Node> q;
    dis[r]=0,q.push(Node(r,dis[r]));
    int cntn=0;
    while(!q.empty()){
        Node tmp=q.top();
        q.pop();
        int idx=tmp.idx;
        if(idx==b) return dis[idx];
        for(int t=head[idx];t!=-1;t=es[t].nxt){
            int v=es[t].v,w=es[t].w;
            if(dis[idx]+w<dis[v]){
                dis[v]=dis[idx]+w;
                q.push(Node(v,dis[v]));
            }
        }
    }
    return -1;
    
}



int main(){
    sf(n),sf(a),sf(b);
    CL(head,-1);
    fr1(i,n){
        int num;sf(num);
        fr1(j,num){
            int v;sf(v);
            if(j==1) add(i,v,0);
            else add(i,v,1);
            
        }
    }
    printf("%d\n",dij(a));

    
    return 0;
}