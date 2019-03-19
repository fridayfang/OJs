# Codeforces Round #542 (Div. 2)
## 题目做不下去的我写一写题解

### A. Be Positive
- 水题,考虑正数，负数个数是否$\geq \lceil \frac{n}{2} \rceil$
### B. Two Cakes
- 给定位置大小为1...n的蛋糕，每种大小共两份，要求两个人从最左边的位置增序各取1..n的蛋糕，求最小步长
- 两个一起考虑，取到第i块蛋糕，两人的位置状态是确定的，无论是a,b两人怎样分布总是占据了这个位置，有点类似蚂蚁相遇后逆行的想法
- 所以我们只需min(蛋糕i到蛋糕i+1),然后累计即可;即处理每种蛋糕位置，然后处理min(abs(cake[i].a-cake[i+1].a)+abs(cake[i].b-cake[i+1].b),abs(cake[i].a-cake[i+1].b)+abs(cake[i].b-cake[i+1].a))
### C. Connect
- 数据量很小，可以暴力做
- 注意题目说只可以修一条通道
- dfs位置(r1,c1)连通的区域，将位置存起来;dfs位置(r2,c2);然后暴力找吧
### D1. Toy Train (Simplified) & D2. Toy Train
- D2相对D1只是数据量更大，D1一步一步模拟能做出来，D2则要求你发现其中规律
- n个站点，每个站点有若干糖果，每个糖果有目标站点；列车只能循环的经过站点123..n123..这样，每次只能carry一个糖，问将所有糖都带回目标站点的最少开销(类似1->2开销为1)
- 容易观察的    
    - 1.是每次选取需要运到最远地方的糖是最优的选择
    - 2.所有站点全部运完的时间是每个站点糖果被运完时间的最长者
    - 3.之所以1是最优选择是因为可以将需要运到最近地方的糖留在了最后，所以我们只需要对每个站点处理需运到最近地方的糖果
#### code

```cpp
#include <bits/stdc++.h>
using namespace std;
//author:fridayfang
//date:19 2月 26
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 5000 + 5;
const int maxm = 20000+5;

int dis[maxn];//记录源站点到目的站点最近的距离
int num[maxn];//记录站点糖的数量;
//从站点i除法运完站点j的糖的时间
//(j-i+n)%n+n*(num[j]-1)+dis[j]
//枚举j得到最大时间则是所求
int n,m;


int main(){
    sf(n),sf(m);
    fr1(i,m){
        int a,b;
        sf(a),sf(b);
        if(num[a]){
            dis[a]=min(dis[a],(b-a+n)%n);
        }
        else dis[a]=(b-a+n)%n;
        num[a]++;
    }
    fr1(i,n){
        int ans=0;
        fr1(j,n){
            ans=max(ans,(j-i+n)%n+n*(num[j]-1)+dis[j]);
        }
        printf("%d ",ans);
    }
    

    return 0;
}
```
### E. Wrong Answer
- 这是一个构造题，看的是官方题解
- 构造 $-1,a_1,a_2,...a_{n}$,其中$a_1..a_{n-1}>=1$,记$S=\sum_0^{n-1}a_i$,则错误算法答案为$(S+1)*(n-1)$,正确算法答案为$n*S$
- 令$n*S-(S+1)*(n-1)=k$,$S+1=k+n$
- 将(k+n)分到剩余(n-1)个元素中
- 我的做法是先寻找合适的n,我寻找的是比恰好合适的n至少>1的n
- 然后进行分配
#### code

```cpp
#include<bits/stdc++.h>
using namespace std;
#define fr0(i, m) for(int i=0;i<m;i++)

//构造题
int k;
int ans[2004];
int a[2000];
int main(){
    ans[2]=-1;
    scanf("%d",&k);
    //寻找n
    int n;
    for(n=2;n<=2000;n++){
        if((1002000+k)<=(n-1)*1000000) break;
    }
    int x=(n+k)/(n-2);
   //printf("db %d %d\n",x,n);
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        if(i==0) a[0]=-1;
        else if(i==n-1){
            a[i]=n+k-x*(n-2);
            //printf(" %d",n+k-x*(n-2));
        }
        else{
            a[i]=x;
        }
    }

    fr0(i,n){
        printf("%d ",a[i]);
    }
    return 0;
}
```
