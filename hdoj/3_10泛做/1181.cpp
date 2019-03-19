#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
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
//date:19 3月 10
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int head[30],vis[30];
struct Edge{int u,v,nxt;}es[800];
int cnt;
char s[100];
int src,des;
void adde(int u,int v){es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt;cnt++;}
int bfs(){
    int s='b'-'a',d='m'-'a';
    queue<int> q;q.push(s);vis[s]=1;
    while(!q.empty()){
        int tmp=q.front();q.pop();
        if(tmp==d) return 1;
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int v=es[t].v;
            if(!vis[v])q.push(v);
        }
    }
    return 0;
}
int dfs(int cur){
    //db(cur);
    if(cur==des) return 1;
    for(int t=head[cur];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(!vis[v]){
            vis[v]=1;
            if(dfs(v)) return 1;
            vis[v]=0;

        }
    }
    return 0;
    
}

int main(){
    src='b'-'a';des='m'-'a';
    CL(head,-1),CL(vis,0);
    while(~scanf("%s",s)){
        if(s[0]!='0'){
            int len=strlen(s);
            int u=s[0]-'a',v=s[len-1]-'a';
            adde(u,v);
        }
        else{
            //
            vis[1]=1;
            if(dfs(1))printf("Yes.\n");
            else printf("No.\n");
            cnt=0;
            CL(head,-1),CL(vis,0);

        }
    }
    
    return 0;
}