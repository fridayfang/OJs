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
const int maxn = 1e5 + 5;
const int maxm = 1e6+5;
//hdu dp problems
//dp[j] ends with j maxsum
//dp[j]=max(dp[j-1]+val[j],val[j])
//path[j]=path[j-1] or j
int val[maxn],dp[maxn],path[maxn];
int n;

int main(){
    int t;sf(t);
    for(int cnt=1;cnt<=t;cnt++){

        
        sf(n);
        fr1(i,n)sf(val[i]);
        dp[0]=-inf;
        for(int i=1;i<=n;i++){
            if(dp[i-1]+val[i]>=val[i]){dp[i]=dp[i-1]+val[i],path[i]=path[i-1];}
            else {dp[i]=val[i];path[i]=i;}
        }
        int maxid=max_element(dp+1,dp+1+n)-dp;
        int maxv=dp[maxid];
        printf("Case %d:\n",cnt);
        printf("%d %d %d\n",maxv,path[maxid],maxid);
        if(cnt<t)printf("\n");
    }
    
    return 0;
}