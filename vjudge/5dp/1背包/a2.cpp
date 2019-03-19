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
const int maxn = 1000 + 5;
const int maxm = 1e6+5;
//背包九讲
//0-1背包问题，每个物品只能选择一次
//dp[i][j] 容量为j的背包选择前i个物品
//dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]])
//滚动数组 dp[j]=max(dp[j],dp[j-v[i]]+w[i])
//如果j按照从小到大枚举，则此时dp[j-v[i]] 是dp[i][j-v[i]]而不是dp[i-1][j-v[i]]
//所以对j从大到小枚举，那么dp[j-v[i]]就是旧的(尚未考虑第i个物品的)
//dp 全部初始化为0，
int dp[maxn];
int main(){
    int N,V;sf(N),sf(V);
    for(int i=1;i<=N;i++){
        int v,w;sf(v),sf(w);
        for(int j=V;j>=v;j--){
            dp[j]=max(dp[j-v]+w,dp[j]);
        }
    }
    printf("%d\n",dp[V]);
    
    return 0;
}