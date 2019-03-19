#include<bits/stdc++.h>
using namespace std;
const int N=105;
vector<int> G[N];
vector<pair<int,int>> ans;
int low[N],dfn[N];
int dfs_clock;
void dfs(int u,int fa){
    low[u]=dfn[u]=++dfs_clock;
    for(auto v: G[u]){
        if(!dfn[v]){
            dfs(v,u);low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                ans.push_back(make_pair(min(u,v),max(u,v)));
            }
        }else if(v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            G[i].clear();
        }
        for(int i=0;i<n;i++){
            int u,v,k;
            scanf("%d (%d)",&u,&k);
            while(k--){
                scanf("%d",&v);
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        ans.clear();
        dfs_clock=0;
        memset(dfn,0,sizeof(dfn));
        for(int i=0;i<n;i++){
            if(!dfn[i]) dfs(i,-1);
        }
        sort(ans.begin(),ans.end());
        printf("%d critical links\n",ans.size());
        for(auto v: ans){
            printf("%d - %d\n",v.first,v.second);
        }
        puts("");
    }
    return 0;
}