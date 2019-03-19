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
const int maxn = 4e4 + 5;
const int maxm = 8e4+5;
//倍增法LCA竟然T了
//我决定直接DFS
int n,q,tmp,head[maxn],cnt;
struct Edge{int u,v,w,nxt;}es[maxm];
void adde(int u,int v,int w){es[cnt].u=u,es[cnt].v=v,es[cnt].w=w,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
int dis[maxn],s,d;
int dfs(int u,int fa,int w){
    dis[u]=dis[fa]+w;
    if(u==d) return dis[u];
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int u=es[t].u,v=es[t].v,wei=es[t].w;
        if(v!=fa){
            int tmp=dfs(v,u,wei);
            if(tmp!=0) return tmp;
        }
    }
    return 0;
}



int main(){
    int t;sf(t);
    while(t--){
        cnt=0;
        sf(n),sf(q);CL(dis,0),CL(head,-1);
        fr1(i,n-1){int u,v,w;sf(u),sf(v),sf(w);adde(u,v,w),adde(v,u,w);}
        fr1(i,q){
            CL(dis,0);
            sf(s),sf(d);
            //db(s),db(d);
            pr(dfs(s,0,0));
        }
    }
    
    return 0;
}