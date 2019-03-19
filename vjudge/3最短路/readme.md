# (写给自己看)最短路系列
## dijkstra算法

### 思想
- 无负权的单源最短路
- 每次扩展的是最短路径的点
- ```priority_queue<node>``` 可轻松实现,同一节点可能有不同距离在队列中，但每次出优先队列都是最小的，也就是最短距离
- [poj1874](http://poj.org/problem?id=1847)

```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 2æœˆ 27
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
```

## bellmanford

### 思想
- 类似动态规划,求不超过$0,1,2..(n-1)$条边的最短路径
- 每次枚举E条边$<u,v>,dis[v]<dis[u]+w[u][v]$ 则更新dis[v]
- 可判负环，$n-1$此后还能松弛则有负权环 O(E*V)
- 优化算法 SPFA
> 维护一个队列，里面存放所有需要进行迭代的点。初始时队列中只有一个
源点S。用一个布尔数组记录每个点是否处在队列中。  

> 每次迭代，取出队头的点v，依次枚举从v出发的边v->u， 若
Dist[v]+len(v->u) 小于Dist[u]，则改进Dist[u]（可同时将u前驱记为v）。
此时由于S到u的最短距离变小了，有可能u可以改进其它的点，所以若u不在
队列中，就将它放入队尾。这样一直迭代下去直到队列变空，也就是S到所
有节点的最短距离都确定下来，结束算法。 若一个点最短路被改进的次数达
到n ，则有负权环(原因同B-F算法） 。 可以用spfa算法判断图有无负权环   

> 在平均情况下， SPFA算法的期望时间复杂度为O(E)

- [p1716](http://poj.org/problem?id=1716)(这个好像是最长路，例题不太好)
```cpp
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
const int maxn = 1e4 + 5;
const int maxm = 1e7+5;
int cnt;
int head[maxn],vis[maxn],dis[maxn],ct[maxn];//记录每个点进入队列次数
struct Edge{
    int v,nxt,w;
}es[maxm];
void add(int u,int v,int w){
    es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u];
    head[u]=cnt,cnt++;
}
int spfa(int r,int d){//d 是目的节点
    //最长路径
    //printf("db %d %d %d\n",r,d,n);
    CL(dis,128);//有负权，dis[]求最长路应清-inf
    //printf("db %d\n",dis[128]);
    dis[r]=0;
    queue<int> q;q.push(r);
    vis[r]=1;//表示进入队列
    while(!q.empty()){
        int tmp=q.front();q.pop();
        vis[tmp]=0;//表示出队列
        //printf("db %d dis: %d\n",tmp,dis[tmp]);
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            //printf("db u->v %d->%d\n",tmp,es[t].v);
            int v=es[t].v,w=es[t].w;
            if(dis[tmp]+w>dis[v]){
                dis[v]=dis[tmp]+w;
                if(vis[v]) continue;
                q.push(v);vis[v]=1;
                //if(ct[v]>=n) return -1;//表示有环
            }
        }

    }
    return dis[d];
    
}
int main(){
    int t;sf(t);
    int minv=inf,maxv=0;
    CL(head,-1);
    int r=0;
    while(t--){
        int x,y;sf(x),sf(y);
        add(x,y+1,2);
        r=max(y,r);
    }
    r++;
    for(int i=0;i<r;i++){
        add(i,i+1,0);
        add(i+1,i,-1);
    }
    int ans=spfa(0,r);
    /*
    while(t--){
        int a,b;
        sf(a),sf(b);
        add(a,b+1,2);
        maxv=b>maxv?b:maxv;
        minv=a<minv?a:minv;
    }
    for(int i=minv;i<=maxv;i++){
        add(i,i+1,0);
        add(i+1,i,-1);
    }
    */
    //int ans=spfa(minv,maxv+1,maxv-minv+1);
    printf("%d\n",ans);
    
    return 0;
}
```

## floyd
### 思想
- Floyd-Warshall算法的原理是动态规划。
- 见[wiki](https://zh.wikipedia.org/wiki/Floyd-Warshall%E7%AE%97%E6%B3%95)即懂
- 见[zhihu](https://www.zhihu.com/question/30955032)也可
- 也可解决传递闭包问题
- [poj2139](http://poj.org/problem?id=2139)


```cpp
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
const int maxn = 300 + 5;
const int maxm = 1e6+5;
//floyd
int n,m;
int path[maxn][maxn];
int mp[maxn][maxn];
void floyd(){
    fr1(i,n) mp[i][i]=0;
    fr1(k,n){
        fr1(i,n){
            fr1(j,n){
                //经过1.2...k节点mp[i][j]最短路径
                if(mp[i][k]>=inf||mp[k][j]>=inf) continue;
                if(mp[i][j]>mp[i][k]+mp[k][j]){
                    mp[i][j]=mp[i][k]+mp[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    /*
    fr1(i,n){
        fr1(j,n){
            printf("%d->%d: %d\n",i,j,mp[i][j]);
        }
    }
    */
}

int cowin[maxn];

int main(){
    while(~scanf("%d %d",&n,&m)){
        CL(mp,0x3f);
        while(m--){
            int t;sf(t);
            for(int j=1;j<=t;j++)sf(cowin[j]);
            fr1(i,t)
            fr1(j,t){
                if(i!=j){
                    mp[cowin[i]][cowin[j]]=1;
                    mp[cowin[j]][cowin[i]]=1;
                }
            }
        }
        floyd();
        int ans=inf;
        fr1(i,n){
            int tmp=0;
            fr1(j,n){
                tmp+=mp[i][j];
            }
            ans=min(ans,tmp);
        }
        //cout<<ans*100/(n-1)<<endl;
        double avg=(ans+0.0)/(n-1.0);
        int fi=(int)(avg*100);
        
        printf("%d\n",fi);
    }
    return 0;

}
```