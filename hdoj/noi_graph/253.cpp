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
const int maxn = 30 + 5;
const int maxm = 1e6+5;
struct Edge{int u,v,w;}es[900];
int cnt;
void adde(int u,int v,int w){es[cnt].u=u,es[cnt].v=v,es[cnt].w=w,cnt++;}
bool cmp(Edge e1,Edge e2){return e1.w<e2.w;}
int fa[30];
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
int n;
char s1[3],s2[3];
int main(){
    while(scanf("%d",&n)&&n){
        cnt=0;
        for(int i=0;i<n-1;i++){
            scanf("%s",s1);int u=s1[0]-'A';
            int num;sf(num);
            fr0(j,num){
                scanf("%s",s2);int v=s2[0]-'A';
                int w;scanf("%d",&w);adde(u,v,w);
            }
        }
        //build the graph
        sort(es,es+cnt,cmp);
        for(int i=0;i<n;i++)fa[i]=i;
        int sel_edge=0,mst=0;
        for(int i=0;i<cnt;i++){
            if(sel_edge==n-1) break;
            int u=es[i].u,v=es[i].v,w=es[i].w;
            int x=find(u),y=find(v);
            if(x!=y){
                fa[x]=y;
                mst+=w;
                sel_edge++;
            }
        }
        pr(mst);

    }

    
    return 0;
}