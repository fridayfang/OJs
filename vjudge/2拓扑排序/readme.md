# 拓扑排序
## 题目做的烦，题解写着玩

### [POJ 2762 Going from u to v or from v to u?](http://poj.org/problem?id=2762)   
- 有向图，<u,v>之间定义这样的关系，u能到达v或者v能到达u，则满足关系
- 观察知，即拓扑排序中队列中不能有两个节点

#### code
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
//date:19 2æœˆ 25
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e3 + 5;
const int maxm = 6010;
struct Edge{
    int u,v,nxt;
}es[maxm];
int n,m;
int head[maxn],cnt,deg[maxn];
void add(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u];
    head[u]=cnt,deg[v]++;
    cnt++;
}
bool topo(){
    queue<int> q;
    fr1(i,n){if(deg[i]==0) q.push(i);}
    //db(q.size());
    while(!q.empty()){
        if(q.size()>=2) return false;
        int tmp=q.front();
        q.pop();
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int u=es[t].u,v=es[t].v;
            if((--deg[v])==0) q.push(v);
        }
    }
    return true;
    
}



int main(){
    int t;
    sf(t);
    while(t--){
        sf(n),sf(m);
        CL(head,-1);
        CL(deg,0);
        cnt=0;
        fr1(i,m){
            int u,v;
            sf(u),sf(v);
            add(u,v);
        }
        if(topo()) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}
```
### [POJ 3687 Labeling Balls](http://poj.org/problem?id=3687)
- 重量为1..n的球要标号为1...n;给出约束<u,v> 表示编号u的球要轻于编号v;如果有多种情况要求输出编号1的尽可能最轻，编号2的尽可能最轻....的情况
- 好多要求啊
- 一般想法按编号建图，拓扑排序的结果即为重量序
- 一种错误做法:优先将编号小的出队列，因为要求是编号小的尽可能轻，而不是轻的尽可能小
- 正确:逆向建图，让编号大的优先出队列占据最重的球，娜么编号小的就尽可能轻了

#### code
```cpp
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
```
### [POJ 1270 Following Orders](http://poj.org/problem?id=1270)
- 给出约束，求出所有可能
- 可以记录已访问的节点数作为dfs的出口
- 读入用gets()
- 拓扑排序+回溯

#### code

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
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int mp[30][30],deg[30],vis[30],out[30];//init -1
char str[100];
//遍历拓扑排序所有可能
int n;
void dfs(int num){//num记录已经存储第几个了
    if(num==n){
        //出口
        for(int i=0;i<n;i++){
            printf("%c",'a'+out[i]);
        }
        printf("\n");
        return ;
    }

    for(int i=0;i<26;i++){
        
        if(deg[i]==0&&!vis[i]){
            //删掉点
            for(int j=0;j<26;j++){
                if(mp[i][j]==1){
                    deg[j]--;
                }
            }

        
            vis[i]=1;
            out[num]=i;
            dfs(num+1);
            //恢复状态
            vis[i]=0;
            for(int j=0;j<26;j++){
                if(mp[i][j]==1){
                    deg[j]++;
                }
            }


        }
    }



}

int main(){
    while(gets(str)!=NULL){
        CL(deg,-1),CL(mp,0),CL(vis,0);
        int cnt=0;
        for(int i=0;i<strlen(str);i++){
            if(str[i]>='a'&&str[i]<='z'){
                int x=str[i]-'a';
                deg[x]=0;
                cnt++;
            }
        }
        n=cnt;
        gets(str);
        int pos=0;
        int tmp[100];
        for(int i=0;i<strlen(str);i++){
            if(str[i]>='a'&&str[i]<='z'){
                tmp[pos++]=str[i]-'a';
            }
        }
        for(int i=0;i<pos;i+=2){
           // printf("add %c %c\n",tmp[i]+'a',tmp[i+1]+'a');
            mp[tmp[i]][tmp[i+1]]=1;
            deg[tmp[i+1]]++;
        }
        dfs(0);
        printf("\n");

    }
    return 0;
    
}
```
### [POJ 1094 Sorting It All Out](http://poj.org/problem?id=1094)
- 恶心之处在于要求没添加一条边就要求你检测是否有矛盾或者唯一确定(出现这两种情况就结束这个case但要继续读入)
- 就是检测环(dfs或toposort)

### code

```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
using namespace std;
//author:fridayfang
//date:19 2æœˆ 23
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define sfs(c) scanf("%s",c)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
struct Edge{
    int u,v,nxt;
}es[900];
int cnt;
int head[26];
int deg[26],in[26];
char srt[26];
void add(int u,int v){
    //printf("db add edge %d %d\n",u,v);
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u];
    head[u]=cnt;
    in[v]++;
    cnt++;
}
int n,m;
char str[5];
bool flag;
int topo(){
    int idx=0;
    queue<int> q;
    fr0(i,n){
        if(deg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        if(q.size()>=2) flag=true;
        int tmp=q.front();
        q.pop();
        //printf("db %c\t",tmp+'A');
        srt[idx++]=tmp+'A';
        //
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int u=es[t].u,v=es[t].v;
            deg[v]--;
            if(!deg[v]) q.push(v);
            //if((--deg[v])==0){
              //  q.push(v);
            //}
        }
    }
    //printf("idx %d\n",idx);
    for(int i=0;i<n;i++){
        if(deg[i]) return 1;//cycle inconsitence
    }
    if(!flag) return 2;//
    else return 3;

}


int main(){
    while(scanf("%d %d",&n,&m)&&n!=0){
        CL(srt,0);
        CL(in,0);
        CL(head,-1);
        cnt=0;
        int ans=0;
        bool incon=false;
        fr0(i,m){
            sfs(str);
            int u=str[0]-'A',v=str[2]-'A';
            add(u,v);
            flag=false;
            for(int i=0;i<n;i++){
                deg[i]=in[i];
            }
            if(incon) continue;
            ans=topo();
           // printf("db i %d ans %d\n",i,ans);
            if(ans==1){
                incon=true;
                printf("Inconsistency found after %d relations.\n",i+1);
            }
            else if(ans==2){
                incon=true;
                printf("Sorted sequence determined after %d relations: %s.\n",i+1,srt);
            }

        }
        if(!incon) printf("Sorted sequence cannot be determined.\n");


    }

    
    return 0;
}
```

### [POJ 3660 Cow Contest](http://poj.org/problem?id=3660)
- 对有约束限制的图，问哪些节点的序可以确定
- 如果一个点和其余点的关系可以确定那么则这个点的序可以确定
- 而对于没有关系的点可以用floyd算法传递关系即a>b b>c-->a>c
### code
```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
using namespace std;
//author:fridayfang
//date:19 2æœˆ 24
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
const int maxm = 1e6+5;
struct Edge{
    int u,v,nxt;
}es[4600];
int n,m;
//floydç®—æ³•
int mp[maxn][maxn];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mp[i][k]==mp[k][j]&&(mp[i][k]==1||mp[i][k]==-1)){
                    mp[i][j]=mp[i][k];
                }
            }
        }
    }

}
int main(){
    sf(n),sf(m);
    CL(mp,0x3f);
    fr1(i,m){
        int u,v;
        sf(u),sf(v);
        mp[u][v]=1;
        mp[v][u]=-1;
    }
    floyd();
    int ans=0;
    for(int i=1;i<=n;i++){
        bool check=true;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(mp[i][j]!=-1&&mp[i][j]!=1){
                check=false;
                break;
            }
            
        }
        if(check) ans++;
    }
    printf("%d\n",ans);
    return 0;
}


```