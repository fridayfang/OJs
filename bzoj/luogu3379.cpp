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