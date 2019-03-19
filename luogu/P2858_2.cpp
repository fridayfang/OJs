#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mm1(x) memset(x,-1,sizeof(x))
#define maxn 2010
int dp[maxn][maxn],value[maxn];
int n;
int solve(){
    for(int i=1;i<=n;i++){
        dp[i][i]=value[i]*n;
        //*key:
    }
    //枚举长度：
    for(int len=2;len<=n;len++){
        //枚举起点
        for(int begin=1;begin<=n-len+1;begin++){
            int end=begin+len-1;
            dp[begin][end]=max(dp[begin][end-1]+value[end]*(n-len+1)
            ,dp[begin+1][end]+value[begin]*(n-len+1));

        }

    }
    return dp[1][n];

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",value+i);
    }
    mm1(dp);
    printf("%d\n",solve());
    return 0;
}