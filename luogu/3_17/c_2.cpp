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
const int maxn = 5e6 + 5;
const int maxm = 1e6+5;

char str[maxn];
int dp[maxn],rec[maxn];
int n,a,b;


int main(){
    sf(n),sf(a),sf(b);
    scanf("%s",str+1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+a;
        for(int j=i-1;j>0;j--){
            if(str[j]==str[i])rec[j]=rec[j-1]+1;
            else rec[j]=0;
            if(rec[j]>0){
                int x=min(i-j,rec[j]);
                dp[i]=min(dp[i],dp[i-x]+b);
            }
        }
    }
    pr(dp[n]);
    
    return 0;
}