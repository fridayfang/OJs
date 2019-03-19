#include<bits/stdc++.h>
using namespace std;
#define maxn 110
int mar[maxn][maxn];
int dp[maxn][maxn];
//dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1
// if mar[i][j]=1;
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mar[i][j]);
        }
    }
    int maxv=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mar[i][j]){
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                maxv=max(maxv,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    printf("%d\n",maxv);
    return 0;
}