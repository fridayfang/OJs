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
//date:19 3月 01
const int maxn = 1e2 + 5;
const int maxm = 1e6+5;
/*
多重背包问题，物品的数量是有限的
dp[i][j]=max(dp[i-1][j],dp[i-1][j-v]+w,dp[i-1][j-2*v]+2*w....)
滚动后 dp[j]=max(dp[j],dp[j-v]+w,dp[j-2*v]+2*w,...)
j 从大到小枚举

*/
int dp[maxn];


int main(){
    int N,V;sf(N),sf(V);
    for(int i=1;i<=N;i++){
        int v,w,s;sf(v),sf(w),sf(s);
        for(int j=V;j>=0;j--){
            for(int k=0;k<=s;k++){
                if(j>=k*v) dp[j]=max(dp[j],dp[j-k*v]+k*w);
            }
        }
    }
    printf("%d\n",dp[V]);
    
    return 0;
}