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