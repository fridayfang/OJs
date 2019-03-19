#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
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
const int maxn = 100 + 5;
const int maxm = 1e6+5;
int K,N,R;
int maxc;
int cnt,head[maxn];
int minl[maxn],minc[maxn];
struct Edge{
    int u,v,nxt,len,cost;
}es[10010];
void adde(int u,int v,int l,int c){es[cnt].u=u,es[cnt].v=v,es[cnt].len=l,es[cnt].cost=c,es[cnt].nxt=head[u],head[u]=cnt,cnt++;}

struct node{
    int idx,lensum,costsum;

    node(int _i,int _l,int _c):idx(_i),lensum(_l),costsum(_c){}
    bool friend operator <(node n1,node n2){
        return n1.lensum>n2.lensum;//min heap
    }
};
int bfs(){
    priority_queue<node> pq;pq.push(node(1,0,0));
    while(!pq.empty()){
        node tmp=pq.top();pq.pop();
        int u=tmp.idx,l=tmp.lensum,c=tmp.costsum;
        if(u==N&&c<=maxc){return l;}
        //minl[u]=l,minc[u]=c;
        for(int t=head[u];t!=-1;t=es[t].nxt){
            int v=es[t].v,len=es[t].len,cost=es[t].cost;
            if(c+cost<=maxc&&(l+len<minl[v]||c+cost<minc[v])){
                pq.push(node(v,l+len,c+cost));
            }
        }
    }
    return -1;//failed

}


int main(){
    //while(~scanf("%d %d %d",&K,&N,&R)){
        //db(K);
        scanf("%d %d %d",&K,&N,&R);
        maxc=K;
        CL(head,-1);cnt=0;CL(minc,inf),CL(minl,inf);
        for(int i=0;i<R;i++){
            int u,v,l,c;sf(u),sf(v),sf(l),sf(c);
            adde(u,v,l,c);
        }
        int ans=bfs();
        pr(ans);
    //}
    
    return 0;
}