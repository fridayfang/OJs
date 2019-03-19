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
const int maxn = 1e3 + 5;
const int maxm = 1e6+5;
/*
完全背包问题
每件物品有无穷件
dp[i][j]=max(dp[i-1][j],dp[i][j-v[i]]+w[i])
滚动后:dp[j]=max(dp[j],dp[j-v[i]]+w[i])
但注意这里dp[j-v[i]]本来就是新的，所以应该从从小到大枚举

*/
int dp[maxn];

int main(){
    int N,V;sf(N),sf(V);
    for(int i=1;i<=N;i++){
        int v,w;sf(v),sf(w);
        for(int j=v;j<=V;j++){
            dp[j]=max(dp[j],dp[j-v]+w);
        }
    }
    printf("%d\n",dp[V]);
    
    return 0;
}