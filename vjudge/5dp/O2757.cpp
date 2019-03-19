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
const int maxm = 1e6+5;
int a[1010],n;
int dp[1010];

int main(){
    sf(n);fr0(i,n) sf(a[i]);
    fr0(i,n) dp[i]=1;
    int maxv=1;
    for(int j=1;j<n;j++){
        for(int i=0;i<j;i++){
            if(a[j]>a[i]) dp[j]=max(dp[j],dp[i]+1);
        }
        maxv=max(maxv,dp[j]);
    }
    printf("%d\n",maxv);
    
    return 0;
}