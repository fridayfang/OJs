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
//date:19 2月 28
const int maxn = 1e6 + 5;
const int maxm = 6e6+5;
int n,m;
int cnt,head[maxn],dep[maxn];
struct Edge{
    int v,nxt,cap;
}es[maxm];
void add(int u,int v,int cap){
    //printf("db add %d->%d %d\n",u,v,cap);
    es[cnt].v=v,es[cnt].cap=cap,es[cnt].nxt=head[u];
    head[u]=cnt,cnt++;
}
int bfs(int s,int des){
    CL(dep,-1);
    queue<int> q;q.push(s);
    dep[s]=1;
    while(!q.empty()){
        int tmp=q.front();q.pop();
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int v=es[t].v,cap=es[t].cap;
            if(cap>0&&dep[v]==-1){//dep[v]==-1代表未访问过
                dep[v]=dep[tmp]+1;q.push(v);
                if(v==des) return 1;
            }
        }
    }
    return dep[des]>-1?1:0;//是否能到达目的节点
}
int dfs(int s,int fl,int des){//fl流入s的流量,向s的出边增光
    if(s==des||fl<=0) return fl;
    int res=0; //多路增光
    for(int t=head[s];fl&&t!=-1;t=es[t].nxt){
        int v=es[t].v,cap=es[t].cap;
        if(dep[v]==dep[s]+1){
            int f=dfs(v,min(fl,cap),des);
            es[t].cap-=f,es[t^1].cap+=f,res+=f;
            fl-=f;
        }
    }
    if(res==0) dep[s]=-2;
    return res;
}
int main(){
    sf(n),sf(m);
    CL(head,-1);
    fr1(i,n){
        fr1(j,m-1){
            int x,u;sf(x),u=(i-1)*m+j;
            add(u,u+1,x),add(u+1,u,x);//加入横边
        }
    }
    fr1(i,n-1){
        fr1(j,m){
            int x,u;sf(x),u=(i-1)*m+j;
            add(u,u+m,x),add(u+m,u,x);

        }
    }
    fr1(i,n-1){
        fr1(j,m-1){
            int x,u;sf(x),u=(i-1)*m+j;
            add(u,u+m+1,x),add(u+m+1,u,x);
        }
    }
    //printf("db");
    int ans=0;
    int src=1,des=n*m;
    while(bfs(src,des)){
        int add;
        while(add=dfs(src,inf,des)) ans+=add;
        //db(ans);
    }
    printf("%d\n",ans);
    
    return 0;
}