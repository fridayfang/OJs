#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
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
//date:19 3月 17
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fll;
const int maxn = 5e6 + 5;
const int maxm = 1e6+5;
const int maxc=10;
int n,a,b;
ll f[maxn];
string str;
struct SAM{
    int tot,lst,son[maxn][maxc],fail[maxn],len[maxn];
    SAM(){CL(son[0],-1); tot=lst=1;}
    void insert(int x){
        int u=lst,v;len[lst=++tot]=len[u]+1;
        for(;!son[u][x];u=fail[u]){son[u][x]=lst;}
        if(u){
            v=son[u][x];
            if(len[u]+1==len[v]){fail[lst]=v;}
            else{
                len[++tot]=len[u]+1;
                fail[tot]=fail[v];
                memcpy(son[tot],son[v],maxc<<2);
                fail[v]=fail[lst]=tot;
                for(;son[u][x]==v;u=fail[u]){son[u][x]=tot;}
            }
        }
        else{fail[lst]=1;}
    }
}sam;
int main(){
    cin>>n>>a>>b>>str;
    CL(f,0x3f);f[0]=a;
    for(int i=0;i<n;i++){
        sam.insert(str[i]-'a');
        f[i+1]=min(f[i+1],f[i]+a);
        for(int j=i+1,u=1;j<n;j++){
            u=sam.son[u][str[j]-'a'];
            if(!u){break;}
            f[j]=min(f[j],f[i]+b);
        }
    }
    printf("%lld\n",f[n-1]);
    return 0;
}
