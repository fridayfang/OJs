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
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;

int dp[12][110];
//dp[i][j] i个鸡蛋扫描j个区域

int n,m;
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        CL(dp,inf);
        for(int i=0;i<=m;i++){dp[i][0]=0;}

        for(int i=0;i<=n;i++){dp[1][i]=i;}
        //db(i),db(dp[1][i]);}
        //db(dp[1][100]);
        for(int i=2;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=j;k++){
                    dp[i][j]=min(dp[i][j],max(dp[i][j-k],dp[i-1][k-1])+1);
                }
                //db(i),db(j),db(dp[i][j]);
            }
        }
        //db(m),db(n);
        pr(dp[m][n]);
    }
    
    return 0;
}