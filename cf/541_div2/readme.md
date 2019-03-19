# [Codeforces Round #541 (Div. 2)](https://codeforces.com/contest/1131)
## 确认过眼神,是div2的人
## a Sea Battle
### 题意:
将两个紧邻的矩形围起来需要的方块数  
周长+4
## b Draw
### 题意：
给定出现的分数，求最多可能出现的平局数
计算$(x_i:y_i) to (x_{i+1},y_{i+1})$可能出现的平局数，可包含一边，如左边，如果不一样，最后可特判右边是否为平局
### code
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e4 + 5;
const int maxm = 1e6+5;
//author:fridayfang
//date:19 2æœˆ 23
//global varibles

int solve(int a1,int b1,int a2,int b2){
    //including a1:b1
    if(a1==b1&&a2==b2) return a2-a1;
    if(a1==b1) return min(a2,b2)-a1+1;
    else{
        int nex=max(a1,b1);
        if(min(a2,b2)<nex) return 0;
        if(a2==b2) return a2-nex;
        else return min(a2,b2)-nex+1;
    }

}
struct scor{
    int a,b;
}sc[maxn];

int n;
int main(){
    sf(n);
    int a,b;
    //db(solve(0,0))
    fr1(i,n){
        sf(sc[i].a),sf(sc[i].b);
    }
    int ans=0;
    fr1(i,n){
        ans+=solve(sc[i-1].a,sc[i-1].b,sc[i].a,sc[i].b);

    }
    ans+=(sc[n].a==sc[n].b);
    pr(ans);
    
    
    return 0;
}
```
## c Birthday
### 题意:
排列n个数使得$abs(a_{i+1}-a_i)$的最大值最小化，包含$a_{n-1}-a_0$的情况  
构造的做:排序,从小到大一次从两边向中间放，即数组边缘小，数组中心大  
证明:  
假设排序后的结果为$a_0,a_1..a_i,a_{i+1}..a_{n-1}$ ,显然我们的做法不会大于$max(a_{i+2}-a_i)$;  
下面只需证明，任何一种做法都不会小于$max(a_{i+2}-a_{i})$  盗用codeforce图进行证明:
![c](https://codeforces.com/predownloaded/a7/24/a724896694cf5446925a8b730d2f9c165d762257.png)

要使其小于$a_{i+2}-a_{i}$ 则$a_{i+2}$和$a_i$之间必须有$a_{i+1}$,同时$a_{i+2}$右边一定是更大的,$a_i$左边一定是更小的，那么最左端和最右端就矛盾了.
### code
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 100 + 5;
const int maxm = 1e6+5;
//author:fridayfang
//date:19 2æœˆ 23
//global varibles
int hei[maxn];
int ans[maxn];
int n;
int main(){
    sf(n);
    for(int i=0;i<n;i++){
        sf(hei[i]);
    }
    sort(hei,hei+n);
    for(int i=0;i<n;i+=2){
        int a=i>>1;
        int b=n-1-a;
        ans[a]=hei[i];
        if(i+1<n) ans[b]=hei[i+1];

    }
    fr0(i,n){
        printf("%d ",ans[i]);
    }
    
    
    return 0;
}
```
## D. Gourmet choice
### 题意
给出n个菜和m个菜之间的相互关系(>,<,=),问是否矛盾，不矛盾则给出最少需要的等级编号  
并查集缩点+有向无环图的最长路径(注意建图方式)
### code
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define sfs(a) scanf("%s",a);
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 2e3 + 5;
const int maxm = 1e6+5;
//author:fridayfang
//date:19 2月 23
//global varibles
//拓扑排序
int fa[2010];
int head[2010];
int find(int u){
    return fa[u]==u?u:fa[u]=find(fa[u]);
}
void unio(int u,int v){
    int x=find(u),y=find(v);
    fa[x]=y;
}
char mp[1005][1005];
int n,m;//n行
struct edge{
    int u,v,nxt;
}es[1000*1000+10];
int deg[2010];
int cnt;
void add(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u];
    head[u]=cnt;
    deg[v]++;
    cnt++;
}
int dp[2010];
int vis[2010];
int topo(){
    queue<int> q;
    for(int i=0;i<m+n;i++){
        if(find(i)==i&&deg[i]==0){
            q.push(i);
            dp[i]=1;
        }
    }
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int u=es[t].u,v=es[t].v;
            deg[v]--;
            if(!deg[v]) q.push(v);
            dp[v]=max(dp[v],dp[tmp]+1);
        }
    }
    //have cycle?
    for(int i=0;i<m+n;i++){
        if(find(i)==i&&deg[i]!=0){
            return 1;
        }
    }
    return 0;
}
int main(){
    sf(n),sf(m);
    for(int i=0;i<n+m;i++){
        fa[i]=i;
    }
    fr0(i,n){
        sfs(mp[i]);
        for(int j=0;j<m;j++){
            if(mp[i][j]=='='){
                unio(i,j+n);
            }
        }
    }
    //合并完成
    //建图
    CL(head,-1);
    fr0(i,n){
        fr0(j,m){
            int x=find(i),y=find(j+n);
            //if(x==y&&mp[i][j]!='='){
                //printf("No\n");//防止自己成环
                //return 0;
            //}
            if(mp[i][j]=='>'){
                add(find(j+n),find(i));
            }
            else if(mp[i][j]=='<'){
                add(find(i),find(j+n));
            }
        }
    }
    //topo序的存在性和最长路径
    int ans=topo();
    if(ans==1){
        printf("No\n");
        return 0;
    }
    else{
        printf("Yes\n");
        for(int i=0;i<n;i++){
            int x=find(i);
            printf("%d ",dp[x]);
        }
        printf("\n");
        for(int j=0;j<m;j++){
            int x=find(j+n);
            printf("%d ",dp[x]);
        }
    }

    
    return 0;
}
```
## F. Asya And Kittens
### 题意
从合并的顺序推出相邻顺序,(只有相邻的集合才能合并)  
并查集+模拟链表(自己写的是静态链表)
每次合并将链表也及进行合并，因为合并意味着集合相邻，即这些元素相邻
### code
```cpp
#include <bits/stdc++.h>
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
const int maxn = 150000 + 5;
const int maxm = 1e6+5;
//模拟并查集+静态链表
int nxt[maxn],tail[maxn];//nxt[]存储下一个元素
//nxt[i]=0表示链表结束
//tail[]维护边界
int fa[maxn];//并查集
int find(int u){
    return u==fa[u]?u:fa[u]=find(fa[u]);
}
void unio(int u,int v){
    int x=find(u),y=find(v);
    fa[x]=y;
}

int n;
int main(){
    sf(n);
    for(int i=1;i<=n;i++){
        fa[i]=tail[i]=i;
    }
    int r;
    for(int i=1;i<n;i++){
        int u,v;
        sf(u),sf(v);
        int x=find(u),y=find(v);
        fa[x]=y;
        //y代表的链表扩张，合并
        nxt[tail[y]]=x;//y链表尾部静态指针指向x
        tail[y]=tail[x];//y的尾部成为x的尾部
    }
    r=find(1);
    //输出链表
    //for(int r=find(1);r!=0;r=nxt[r]){
        //printf("%d ",r);
    //}
    while(r!=0){
        printf("%d ",r);
        r=nxt[r];
    }

    
    return 0;
}
```
## e题好复杂,g题不会做
