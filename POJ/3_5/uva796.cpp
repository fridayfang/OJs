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
//date:19 3月 05
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 2e6+5;
int head[maxn],dfn[maxn],low[maxn];
int n,m,cnt,timing,cutnum;
struct Edge{
    int u,v,nxt,iscut;
}es[maxm];
void add(int u,int v){
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}
void tarjan(int u,int fa){
    low[u]=dfn[u]=(++timing);
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(!dfn[v]){
            tarjan(v,u);low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                if(es[t].iscut==0) {es[t].iscut=1,es[t^1].iscut=1;}
                //cutnum++;
            }
        }
        else if(v!=fa)low[u]=min(low[u],dfn[v]);//
    }

}
//


int main(){
    while(scanf("%d",&n)!=EOF){
        //db(n);
        CL(head,-1),CL(dfn,0),CL(low,0),CL(es,0);
        cutnum=cnt=timing=0;
        for(int i=0;i<n;i++){
            int u,num,v;scanf("%d (%d)",&u,&num);
            //db(u),db(num);
            for(int j=1;j<=num;j++){
                sf(v),add(u,v),add(v,u);
            }
        }
        for(int i=0;i<n;i++)if(!dfn[i])tarjan(i,-1);
        int ans=0;
         for(int i=0;i<n;i++){
            for(int t=head[i];t!=-1;t=es[t].nxt){
                int u=es[t].u,v=es[t].v,iscut=es[t].iscut;
                if(v>u&&iscut==1)ans++;
            }
        }
        printf("%d critical links\n",ans);
        for(int i=0;i<n;i++){
            for(int t=head[i];t!=-1;t=es[t].nxt){
                int u=es[t].u,v=es[t].v,iscut=es[t].iscut;
                if(v>u&&iscut==1)printf("%d - %d\n",u,v);
            }
        }
        printf("\n");
    }
    
    return 0;
}