# (写给自己看)匈牙利算法(最大匹配)和KM算法(最佳匹配)

## 匈牙利算法

### 思想
- 不断寻找增广路，每次寻得增广路,交换匹配边和非匹配边,则匹配点数+1
- 这里增广路含义:交错路,即从未匹配点出发经过未匹配边->匹配边->未匹配边->.....->未匹配边
- Konig定理:无权二分图的最大匹配=最小覆盖点集,[证明](http://www.matrix67.com/blog/archives/116)
- 有价值的博客:[blog1](https://www.renfei.org/blog/bipartite-matching.html),[blog2](https://comzyh.com/blog/archives/148/),[blog3]()
- 算法其实并不难

### 模板
模板题目:[poj1274](http://poj.org/problem?id=1274),[poj1325](http://poj.org/problem?id=1325),后者需要konig定理转化

```cpp
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
//date:19 3æœˆ 12
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 200 + 5;
const int maxm = 1e6+5;
int n,m;
int mpp[maxn][maxn];//mp[i][j] means cow i like stall j
int used[maxn];//used[i] for cow i
int linker[maxn];//linker[i] for stall if -1 not match
//used[i],linker[i],i表示的是右边的点
int dfs(int u){// 实际运行dfs()都是左边的点
    for(int i=1;i<=m;i++){
        if(mpp[u][i]&&!used[i]){
            used[i]=1;
            if(linker[i]==-1||dfs(linker[i])){
                linker[i]=u;
                return 1;
            }
        }
    }
    return false;
}
int main(){
    while(~scanf("%d %d",&n,&m)){
        CL(mpp,0);
        fr1(i,n){
            int num,v;sf(num);
            fr1(j,num){sf(v);mpp[i][v]=1;}
        
        }
        //build ok
        int ans=0;
        CL(linker,-1);
        for(int i=1;i<=n;i++){
            CL(used,0);
            if(dfs(i)) ans++;//每次dfs最多指增加一个点i被匹配,原先已经匹配的点依旧被匹配只是边有变化
        }
        pr(ans);
    }
    
    return 0;
}
```


## KM算法求带权图的最佳匹配

### 思想
- 设计了顶标的思路，每次在dfs(u)失败后,通过改变增广路上的点的顶标lx[],ly[]，来加入次大的边
- 一个边被加入<=>$lx[u]+ly[v]==mp[u][v]$
- 顶标变化d,根据满足visx[i]&&!visy[j]的点对来确定,$d=min(d,lx[i]+ly[j]-mp[i][j])$
- 有O(N^3)和O(n^4)写法,后者其实也不是很慢；前者实现一般需要slack[]数组，需要在dfs(u)和顶标变化的时候维护,具体可见代码
- 有价值的blog,[blog1](http://www.cnblogs.com/Lanly/p/6291214.html),[blog2](https://blog.csdn.net/sixdaycoder/article/details/47720471),[blog3](https://www.cnblogs.com/wenruo/p/5264235.html)

### 模板
- [hdu2255](http://acm.hdu.edu.cn/showproblem.php?pid=2255)模板题
- code1 (O(n^4))(我常用的模板，也比较好写)
```cpp
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
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
//date:19 3月 12
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 300 + 5;
const int maxm = 1e6+5;
//先试试O(n^4)写法
 int lx[maxn],ly[maxn];
 int mat[maxn][maxn];
 int n;
 int visx[maxn],visy[maxn];
 int linker[maxn];
 
 bool dfs(int u){
     visx[u]=1;
     for(int i=1;i<=n;i++){
         if(!visy[i]&&(lx[u]+ly[i]==mat[u][i])){
             visy[i]=1;
             if(linker[i]==-1||dfs(linker[i])){
                 linker[i]=u;return true;
             }
         }
     }
     return false;
 }
 int km(){
     CL(linker,-1),CL(lx,0),CL(ly,0);
     for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             lx[i]=max(lx[i],mat[i][j]);
         }
     }
     for(int i=1;i<=n;i++){
         while(true){
             CL(visx,0),CL(visy,0);
             if(dfs(i))break;
             int d=inf;
             for(int x=1;x<=n;x++){
                 for(int y=1;y<=n;y++){
                     if(visx[x]&&!visy[y])d=min(d,lx[x]+ly[y]-mat[x][y]);
                 }
             }
             for(int i=1;i<=n;i++){
                 if(visx[i])lx[i]-=d;
                 if(visy[i])ly[i]+=d;
             }
         }
     }
     int res=0;
     for(int i=1;i<=n;i++){
         res+=mat[linker[i]][i];
     }
     return res;
 }



int main(){
    while(~sf(n)){
        fr1(i,n)fr1(j,n)sf(mat[i][j]);
        int ans=km();
        pr(ans);
    }
    
    return 0;
}
```

- code2 (O(n^3))

```cpp
/*
实际上，O(n^4)的KM算法表现不俗，使用O(n^3)并不会很大的提高KM的运行效率
需要在O(1)的时间找到任意一条边，使用邻接矩阵存储更为方便
*/
#include <cstring>
#include <cstdio>
const int maxn = 305;
const int INF = 0x3f3f3f3f;
int match[maxn],lx[maxn],ly[maxn],slack[maxn];
int G[maxn][maxn];
bool visx[maxn],visy[maxn];
int n,nx,ny,ans;

bool findpath(int x)
{
    int tempDelta;

    visx[x] = true;
    for(int y = 0 ; y < ny ; ++y){
        if(visy[y]) continue;
        tempDelta = lx[x] + ly[y] - G[x][y];
        if(tempDelta ==  0){//(x,y)在相等子图中
            visy[y] = true;
            if(match[y] == -1 || findpath(match[y])){
                match[y] = x;
                return true;
            }
        }
        else if(slack[y] > tempDelta)
            slack[y] = tempDelta;//(x,y)不在相等子图中且y不在交错树中
    }
    return false;
}
void KM()
{

    for(int x = 0 ; x < nx ; ++x){
        for(int j = 0 ; j < ny ; ++j) slack[j] = INF;//这里不要忘了，每次换新的x结点都要初始化slack
        while(true){
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));//这两个初始化必须放在这里,因此每次findpath()都要更新
            if(findpath(x)) break;
            else{
                int delta = INF;
                for(int j = 0 ; j < ny ; ++j)//因为dfs(x)失败了所以x一定在交错树中，y不在交错树中，第二类边
                    if(!visy[j] && delta > slack[j])
                        delta = slack[j];
                for(int i = 0 ; i < nx ; ++i)
                    if(visx[i]) lx[i] -= delta;
                for(int j = 0 ; j < ny ; ++j){
                    if(visy[j])
                        ly[j] += delta;
                    else
                        slack[j] -= delta;
                    //修改顶标后，要把所有的slack值都减去delta
                    //这是因为lx[i] 减小了delta
                    //slack[j] = min(lx[i] + ly[j] -w[i][j]) --j不属于交错树--也需要减少delta，第二类边
                }
            }
        }
    }
}
void solve()
{

   memset(match,-1,sizeof(match));
   memset(ly,0,sizeof(ly));
   for(int i = 0 ; i < nx ; ++i){
        lx[i] = -INF;
        for(int j = 0 ; j < ny ; ++j)
            if(lx[i] < G[i][j])
                lx[i] = G[i][j];
   }
   KM();
}
int main()
{
    while(scanf("%d",&n) != EOF){
        nx = ny = n;
        for(int i = 0 ; i < nx ; ++i)
            for(int j = 0 ; j < ny ; ++j)
                scanf("%d",&G[i][j]);
        solve();
        int ans = 0;
        for(int i = 0 ; i < ny ; ++i)
            if(match[i] != -1)
                ans += G[match[i]][i];
        printf("%d\n",ans);
    }
    return 0;
}
```






