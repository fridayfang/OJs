#include<bits/stdc++.h>
using namespace std;
#define maxn 205
int dp1[maxn][maxn],dp2[maxn][maxn],value[maxn];
int sum[maxn];
//value[i]=value[i+n]
//区间dp
//dp[i][j]表示i..j最优得分
//O(N^3)
int n;
int min_ans=0x3f3f3f3f,max_ans=-1;
#define mm1(x) memset(x,-1,sizeof(x));
#define mm2(x) memset(x,0x3f,sizeof(x));
void init(){
    mm1(dp1);
    mm2(dp2);
    for(int i=1;i<=2*n;i++){
        sum[i]=sum[i-1]+value[i];
    }
}
void solve(){
    for(int i=1;i<=2*n;i++){
        dp1[i][i]=dp2[i][i]=0;

    }
    for(int len=2;len<=n;len++){
        for(int begin=1;begin<=(2*n-len+1);begin++){
            int end=begin+len-1;
            for(int j=begin;j<=end-1;j++){
                dp1[begin][end]=max(dp1[begin][end],dp1[begin][j]+dp1[j+1][end]+sum[end]-sum[begin-1]);
                dp2[begin][end]=min(dp2[begin][end],dp2[begin][j]+dp2[j+1][end]+sum[end]-sum[begin-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        //printf("db max:%d min:%d\n",dp1[i][i+n-1],dp2[i][i+n-1]);
        max_ans=max(max_ans,dp1[i][i+n-1]);
        min_ans=min(min_ans,dp2[i][i+n-1]);
    }

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",value+i);
        value[i+n]=value[i];
    }
    init();
    solve();
    printf("%d\n%d\n",min_ans,max_ans);
    return 0;

}