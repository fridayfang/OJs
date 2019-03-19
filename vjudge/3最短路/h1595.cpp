#include <bits/stdc++.h>
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
//date:19 2月 26
//删边用邻接矩阵更快
const int maxn = 1000 + 5;
const int maxm = 5e5+5;
int N,M,cnt;
int vis[maxn],dis[maxn];
int path[maxn],mp[maxn][maxn];
int dij(int r,bool pathn){
    CL(dis,0x3f),CL(vis,0);
    dis[r]=0,vis[r]=1;
    while(r!=N){
        //printf("db %d\n",mp[1][3]);
        for(int i=1;i<=N;i++){
            if(mp[r][i]<inf&&!vis[i]){
                if(dis[r]+mp[r][i]<dis[i]){
                    dis[i]=dis[r]+mp[r][i];
                    if(pathn) path[i]=r;//record
                }
            }
        }
        int mind=inf,minv=-1;
        /*
        printf("dist:");
        for(int i=1;i<=N;i++){
            printf("%d ",dis[i]);
        }
        printf("\n");
        */
        for(int i=1;i<=N;i++){
            if(!vis[i]&&dis[i]<mind){
                mind=dis[i];
                minv=i;
            }
        }
        vis[minv]=1;
        //printf("db v:%d dis[v]:%d\n",minv,dis[minv]);
        r=minv;

    }
    return dis[N];
}

//删边dij
int solve(){
    int ans=dij(1,true);//get pre;
    for(int i=N;i!=1;i=path[i]){
        int u=i,v=path[i];
        int w=mp[u][v];
        mp[u][v]=inf,mp[v][u]=inf;
        ans=max(dij(1,false),ans);
        mp[u][v]=w,mp[v][u]=w;
    }
    return ans;
}




int main(){
    while(~scanf("%d %d",&N,&M)){
        CL(mp,0x3f),CL(path,-1);
        fr0(i,M){
            int u,v,w;
            sf(u),sf(v),sf(w);
            mp[u][v]=w,mp[v][u]=w;
        }
        printf("%d\n",solve());
        
    }
    
    return 0;
}