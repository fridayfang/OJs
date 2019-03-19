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