#include <bits/stdc++.h>
using namespace std;
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
//date:19 3月 04
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 2e4 + 5;
const int maxm = 5e4 +5;
int head[maxn],in[maxn],out[maxn],col[maxn];
int dfn[maxn],low[maxn],ins[maxn];
int n,m,cnt,colcn,timing;
int st[maxn],p;
int scgcnt;
struct Edge{int u,v,nxt;}es[maxm];
void adde(int u,int v){
    //db(u),db(v);
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u],head[u]=cnt,cnt++;
}
void tarjan(int u){
    dfn[u]=low[u]=(++timing);st[p++]=u,ins[u]=1;
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(!dfn[v]){tarjan(v);low[u]=min(low[u],low[v]);}
        else if(ins[v]&&dfn[v]<low[u]){low[u]=dfn[v];}//用min无速度差别
    }
    if(dfn[u]==low[u]){
        int j;
        scgcnt++,colcn++;//scgcnt和colcn是一个东西
        do{
            j=st[p-1],p--,ins[j]=0,col[j]=colcn;
        }while(u!=j);
        
    }
}
int in0cnt,out0cnt;
void calc(){
    for(int i=0;i<cnt;i++){
        int x=col[es[i].u],y=col[es[i].v];
        if(x!=y){out[x]++,in[y]++;}
    }
    for(int i=1;i<=colcn;i++){
        
        if(in[i]==0) in0cnt++;
        if(out[i]==0) out0cnt++;
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    while(scanf("%d %d",&n,&m)!=EOF){
        //db(n),db(m);
        cnt=0,scgcnt=0,colcn=0,timing=0;
        in0cnt=0,out0cnt=0;
        CL(head,-1),CL(in,0),CL(out,0),CL(dfn,0),CL(low,0),CL(ins,0),CL(col,0);
        fr1(i,m){int u,v;sf(u),sf(v);adde(u,v);}
        for(int i=1;i<=n;i++){
            if(!dfn[i]){p=0,tarjan(i);}
        }
        if(scgcnt<=1){printf("0\n");continue;}
        calc();
        //db(in0cnt),db(out0cnt);
        printf("%d\n",max(in0cnt,out0cnt));
    }

    return 0;
}
