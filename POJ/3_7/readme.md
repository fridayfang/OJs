# LCA-倍增法
## 题目又做不下去来写题解了

## 算法思想
- 类似于ST表的思想维护dp[i][j]:节点i向上跳2^j高度的的节点
- 转移方程 $dp[i][j]=dp[dp[i][j-1]][j-1]$注意理解依赖关系,dp[i][j]状态的确定需要dp[x][j-1]
- 所以在每次需要先得到[j-1]的所有状态才能推出[j],即如果写成双重循环j的循环应该在外层
- dfs中完成初始化$dp[i][0]$,同时可完成dp[i][j]的更新
## 用途
- 多次查询两点间路径(维护树上前缀和即可)
- 裸题:最近公共祖先
- 维护树上两点间路径的信息(如min,max),方法如同维护dp[i][j]只要能从info[i][j-1],info[dp[i][j-1]][j-1]->info[i][j]即可,注意dp和info的顺序
- 维护两点路径间区间变化信息
## 模板

```cpp
#include <bits/stdc++.h>
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
//date:19 3月 03
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 5e5 + 5;
const int maxm = 1e6+5;
int dep[maxn],fa[maxn][25],head[maxn];
int n,m,s,cnt,root;
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int _v,int _nxt):v(_v),nxt(_nxt){}
}es[maxm];
void add(int u,int v){
    es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
void dfs(int r,int father){
    dep[r]=dep[father]+1;
    fa[r][0]=father;
    //dp: fa[i][j]=fa[fa[i][j-1]][j-1]
    for(int i=1;(1<<i)<=dep[r];i++) fa[r][i]=fa[fa[r][i-1]][i-1];
    for(int t=head[r];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(v==father) continue;
        else dfs(v,r);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    //x深，先爬到和y深度相同
    while(dep[x]>dep[y]){x=fa[x][(int)log2(dep[x]-dep[y])];}
    if(x==y) return x;
    //统一一起跳
    for(int i=(int)log2(dep[x]);i>=0;i--){
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
int main(){
    CL(head,-1);
    sf(n),sf(m),sf(s);
    fr1(i,n-1){int u,v;sf(u),sf(v);add(u,v),add(v,u);}
    dfs(s,0);
    fr1(i,m){int x,y;sf(x),sf(y);pr(lca(x,y));} 
    return 0;
}
```

- 可以默写板子的题目[luogu3379](https://www.luogu.org/problemnew/show/P3379),[hdu2874](http://acm.hdu.edu.cn/showproblem.php?pid=2874)
- 复杂度O(NlogN),每次查询lca(a,b)是O(logN)
## 有趣的题目

### [luogu1967](http://acm.hdu.edu.cn/showproblem.php?pid=2874)
- 给一个图，多次询问a-b,求a-b之间所有路径中限重最大的(一条路径中限重最小的那一段是这条路径的限重限重)
- 建最大生成树，并维护path[i][j]表示从节点i向上跳2^j步的边的min
- 求lca是即能求出答案
- code如下
```cpp
#include <bits/stdc++.h>
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
//date:19 3月 03
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e5+5;
struct eg{
    int u,v,dis;
    bool friend operator<(eg e1,eg e2){
        return e1.dis>e2.dis;
    }
}egs[maxn];//for kruscal
struct Edge{
    int v,nxt,w;
}es[maxn];//rebuild a graph
int n,m,cnt;
int head[maxn],f[maxn],fa[maxn][21],w[maxn][21],dep[maxn];
void adde(int u,int v,int w){
    es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u];
    head[u]=cnt,cnt++;
}

//w,f同时更新，表示节点i向上跳2^j 的节点和负重
int find(int u){return f[u]==u?u:f[u]=find(f[u]);}
void kruscal(){
    int cnte=0;
    CL(head,-1);
    sort(egs,egs+m);
    //db(egs[0].dis);
    for(int i=0;i<m;i++){
        int u=egs[i].u,v=egs[i].v,dis=egs[i].dis;
        int x=find(u),y=find(v);
        if(x!=y){
            //db(u),db(v),db(dis);
            cnte++;
            adde(u,v,dis),adde(v,u,dis);//建立最大生成树
            //printf("%d %d %d\n",u,v,dis);
            f[x]=y;
        }
    }
    //db(cnte);
}
void dfs(int r,int fath,int we){//dfs 更新f[][],w[][]
    //db(r),db(fath),db(we);
    dep[r]=dep[fath]+1;
    fa[r][0]=fath,w[r][0]=we;
    for(int j=1;(1<<j)<=dep[r];j++){
        fa[r][j]=fa[fa[r][j-1]][j-1];
        w[r][j]=min(w[fa[r][j-1]][j-1],w[r][j-1]);
        //db(j),db(fa[r][j]),db(w[r][j]);
    }
    for(int t=head[r];t!=-1;t=es[t].nxt){
        int v=es[t].v,w=es[t].w;
        if(v!=fath){
            dfs(v,r,w);//应该没问题??
        }
    }

}
int lca(int x,int y){
    //db(x),db(y);
    if(find(x)!=find(y)) return -1;
    if(dep[x]==0) dfs(x,0,inf);//dep[] 代表之前没有dfs
    int ans=inf;
    //db(dep[x]),db(dep[y]);
    if(dep[x]<dep[y])swap(x,y);
    //db(dep[x]),db(dep[y]);
    while(dep[x]>dep[y]){
        int len=(int)log2(dep[x]-dep[y]);
        //db(w[x][len]),db(ans);
        ans=min(ans,w[x][len]);
        x=fa[x][len];
    }
    //db(x),db(y),db(ans);
    if(x==y){return ans;}
    //db((int)log2(dep[x]));
    for(int j=(int)log2(dep[x]);j>=0;j--){//fa[][]初始化为0，即使跳过了也为0
        if(fa[x][j]!=fa[y][j]){
            //db(fa[x][j]),db(j);
            ans=w[x][j]<w[y][j]?min(w[x][j],ans):min(w[y][j],ans);
            x=fa[x][j],y=fa[y][j];
        }
    }
    //还要向上爬一步
    ans=min(ans,w[x][0]);ans=min(ans,w[y][0]);
    return ans;
}


int main(){
    sf(n),sf(m);
    fr1(i,n)f[i]=i;
    fr0(i,m){int u,v,w;sf(u),sf(v),sf(w);egs[i].u=u,egs[i].v=v,egs[i].dis=w;}
    kruscal();
    int s;sf(s);
    fr1(i,s){int x,y;sf(x),sf(y);pr(lca(x,y));}

    
    return 0;
}
```

### [cf609e](http://codeforces.com/problemset/problem/609/E)
- 与上面题目很像，思路应该有借鉴的成分
- 给一个无向图，求出包含u-v边的最小生成树的权值和
- 不在最小生成树上的边(x,y)>=从x到y在树上路径最重的边
> Some spanning tree is minimal if and only if the weight of any other edge (x, y) (not from spanning tree) is not less than the weight of the heaviest edge on the path from x to y in spanning tree.
- MST, 维护路径上最重的边(同上),将(x-y)替换掉最重的边
- 真的是很好的题目
```cpp
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
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
//date:19 3月 07
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 4e5+5;
int head[maxn],fa[maxn];
int dp[maxn][20],dep[maxn];
int heavy[maxn][20];//维护向上最重的边
int cnt,n,m;
struct Edge{
    int u,v,nxt,w;
    Edge(){}
    Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w),nxt(-1){}
}es[maxm],es2[maxm],es3[maxm];
void adde(int u,int v,int w){
    es[cnt].u=u,es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
//es2 kruscal算法
bool cmp(Edge e1,Edge e2){return e1.w<e2.w;}
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
ll kruscal(){
    fr1(i,n)fa[i]=i;
    sort(es2,es2+m,cmp);
    int cnte=0;
    ll len=0;
    for(int i=0;i<m;i++){
        int u=es2[i].u,v=es2[i].v,w=es2[i].w;
        int x=find(u),y=find(v);
        if(x!=y){
            cnte++;
            fa[x]=y;len+=w;
            adde(u,v,w),adde(v,u,w);
        }
        if(cnte>=n-1)break;
    }
    return len;
    //build a tree
}
void dfs(int u,int father,int d,int wei){
    dep[u]=d;dp[u][0]=father,heavy[u][0]=wei;
    for(int i=1;(1<<i)<=dep[u];i++)dp[u][i]=dp[dp[u][i-1]][i-1];
    for(int i=1;(1<<i)<=dep[u];i++)heavy[u][i]=max(heavy[u][i-1],heavy[dp[u][i-1]][i-1]);
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int u=es[t].u,v=es[t].v,w=es[t].w;
        if(v!=father)dfs(v,u,d+1,w);
    }
}
int lca(int u,int v){//u-lac(u,v)-v这条链上的最大权重
    int maxlen=0;
    if(dep[u]<dep[v])swap(u,v);
    while(dep[u]>dep[v]){
        maxlen=max(maxlen,heavy[u][(int)log2(dep[u]-dep[v])]);
        u=dp[u][(int)log2(dep[u]-dep[v])];
        }
    //dep[u]=dep[v]
    if(u==v) return maxlen;
    for(int j=18;j>=0;j--){
        if(dp[u][j]!=dp[v][j]){
            maxlen=max(maxlen,max(heavy[u][j],heavy[v][j]));
            u=dp[u][j],v=dp[v][j];
        }
    }
    maxlen=max(maxlen,max(heavy[u][0],heavy[v][0]));
    return maxlen;
}



int main(){
    sf(n),sf(m);
    CL(head,-1);
    fr0(i,m){
        int u,v,w;sf(u),sf(v),sf(w);es2[i]=Edge(u,v,w),es3[i]=Edge(u,v,w);
    }
    ll minlen=kruscal();
    int root=1;//根节点
    dfs(root,0,1,0);
    //db(minlen);
    fr0(i,m){
        int u=es3[i].u,v=es3[i].v,w=es3[i].w;
        int maxlen=lca(u,v);
        //db(maxlen),db(w);
        ll ans=minlen-maxlen+w;
        printf("%lld\n",ans);
    }


    
    return 0;
}
```
## [hdu2586](http://acm.hdu.edu.cn/showproblem.php?pid=2586)
- 倍增法好像会T
- 可直接DFS，因为询问很少
- 可能tarjan离线算法可做，可是我不会
- poj也有几道水题，不一一记录,大概是求路径和dis[u]+dis[v]-2*dis[lca(u,v)]
- 还有边权，点权修改的题目...(挖坑)