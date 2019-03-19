
#include <iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define rng(a) a.begin(),a.end()
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
//author:fridayfang
//date:19 2æœˆ 26
const int maxn = 500 + 5;
const int maxm = 1e3+5;
int F,P,C,M;
struct Node{
    int idx,dis;
    Node(int _idx,int _dis):idx(_idx),dis(_dis){}
    friend bool operator < (Node a,Node b){
        return a.dis>b.dis;
    }
};//small heap
int head[maxn],vis[maxn],dis[maxn];
int tag[maxn];
struct Edge{
    int v,nxt,w;
}es[maxm<<1];
int cnt;
void add(int u,int v,int w){
    es[cnt].v=v,es[cnt].w=w;
    es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
void dij(int r){
    CL(vis,0),CL(dis,0x3f);
    dis[r]=0,vis[r]=1;
    int cnt=1;
    priority_queue<Node> q;
    q.push(Node(r,dis[r]));
    while(!q.empty()){
        Node tmp=q.top();
        q.pop();
        cnt++;
        if(cnt>=F) break;
        int idx=tmp.idx;
        vis[idx]=1;
        for(int t=head[idx];t!=-1;t=es[t].nxt){
            int v=es[t].v,w=es[t].w;
            if(!vis[v]&&dis[idx]+w<dis[v]){
                dis[v]=dis[idx]+w;
                q.push(Node(v,dis[v]));
            }
        }

    }
    
}


int main(){
    sf(F),sf(P),sf(C),sf(M);
    CL(head,-1),CL(vis,0),CL(dis,0x3f);
    fr1(i,P){
        int u,v,w;
        sf(u),sf(v),sf(w);
        add(u,v,w);
        add(v,u,w);
    }
    dij(1);
    int cntc=0;
    fr1(i,C){
        int r;sf(r);
        if(dis[r]<=M){
            tag[i]=1;
            cntc++;
        }
    }
    printf("%d\n",cntc);
    fr1(i,C){
        if(tag[i]) printf("%d\n",i);
    }
    
    return 0;
}