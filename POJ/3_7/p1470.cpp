#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
#pragma GCC optimize("O3")
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
//date:19 3月 07
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1000 + 5;
const int maxm = 1000+5;
int head[maxn],dp[maxn][11],dep[maxn];

int lg[maxn];
int tag[maxn];
int sum[maxn];
int cnt,n,m;
struct Edge{int u,v,nxt;}es[maxm];
void adde(int u,int v){es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
void dfs(int u,int fa,int de){
    dep[u]=de;dp[u][0]=fa;
    //for(int i=1;(1<<i)<=dep[u];i++)dp[u][i]=dp[dp[u][i-1]][i-1];
    //先求浅层，在求深层
    //这种写法很巧妙,dfs进入最深一层实际dep[],dp[][0]全部求出
    //
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int u=es[t].u,v=es[t].v;
        if(v!=fa){dfs(v,u,de+1);}
    }
}

void build(){
    //状态的依赖是求解的顺序

    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10&&j<=lg[i];j++){
            dp[i][j]=dp[dp[i][j-1]][j-1];//错误写法
            //这种写法是说:节点i向前跳2^j结果需要依赖
            //依赖节点跳2^j-1,假设这个点是x
            //还需依赖x跳2^j-1 然而x可能比i大还未求出
        }
    }
    */
    for(int j=1;j<=10;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }

}

int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    while(dep[u]>dep[v]){u=dp[u][(int)log2(dep[u]-dep[v])];}
    if(u==v) return u;
    for(int j=10;j>=0;j--){
        if(dp[u][j]!=dp[v][j]){u=dp[u][j],v=dp[v][j];}
    }
    return dp[u][0];
}
int main(){
    for(int i=1;i<=1000;i++){
        if(i==1) lg[i]=0;
        else lg[i]=lg[i-1]+(i==(1<<(lg[i-1]+1)));
    }
    while(scanf("%d",&n)!=EOF){
        cnt=0;
        int u,v,num,root=0;
        CL(head,-1),CL(sum,0),CL(dp,0),CL(tag,0),CL(dep,0);
        for(int i=1;i<=n;i++){
            scanf("%d:(%d)",&u,&num);
            while(num--){
                sf(v);adde(u,v),adde(v,u);tag[v]=1;
            }
        }
        for(int i=1;i<=n;i++){if(!tag[i]){root=i;break;}}
        dfs(root,0,1);
        build();
        sf(m);
        int a,b;
        for(int i=0; i<m; i++){
            while(getchar() != '(');
            scanf("%d%d", &a, &b);
            while(getchar() != ')');
            sum[lca(a, b)] ++;
        }
        fr1(i,n){
            if(sum[i]!=0){
                printf("%d:%d\n",i,sum[i]);
            }
        }
    }
    
    return 0;
}