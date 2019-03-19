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
const int maxn = 5e4 + 5;
const int maxm = 1e6+5;

int fa[maxn];
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
void uni(int u,int v){
    int x=find(u),y=find(v);
    if(x!=y){fa[x]=y;}
}
int n,m;
int has[maxn];

int main(){
    int cases=0;
    while(scanf("%d %d",&n,&m)&&n){
        cases++;
        CL(has,0);
        fr1(i,n)fa[i]=i;
        fr1(i,m){
            int u,v;sf(u),sf(v);
            uni(u,v);
        }
        int cnt=0;
        fr1(i,n){
            int x=find(i);
            if(!has[x]){cnt++,has[x]=1;}
        }
        printf("Case %d: %d\n",cases,cnt);

    }
    
    return 0;
}