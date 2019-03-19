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
//dp[i][j] 前j个元素分成i段 maxsum(必须含j)
//dp[i][j]=max(dp[i][j-1]+val[j],dp[i-1][k]+val[j])
//考虑元素j是单独成段，还是于j-1相连成段1
//优化:注意到
//自己实现i,j是反的
ll val[maxn];
ll sum[maxn],dp[maxn][2];
int n,m;

int main(){
    while(~scanf("%d %d",&m,&n)){
        fr1(i,n){scanf("%lld",&val[i]);sum[i]=sum[i-1]+val[i];}
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        //dp[i][j]=max(dp[i-1][j]+val[i],dp[k][j-1]+val[i])
        //dp[i][j]=max(dp[i-1][j]+val[i],dp[k][j^1]+val[i])
        //滚动掉的是j,所以j在最外层，你必须把j的前一层存好
        for(int j=1;j<=m;j++){
            for(int i=j;i<=n;i++){
                int t=j%2;//must i>=j
                if(i==j){dp[i][t]=sum[j];continue;}//i==j
                dp[i][t]=dp[i-1][t]+val[i];//i>j->i-1>=j
                for(int k=j-1;k<=i-1;k++){
                    dp[i][t]=max(dp[i][t],dp[k][t^1]+val[i]);
                }
                //db(i),db(j),db(dp[i][t]);
            }
        }
        printf("%lld\n",dp[n][m%2]);
    }

    
    return 0;
}