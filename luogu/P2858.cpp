#include<bits/stdc++.h>
using namespace std;
//记忆化搜素
#define maxn 2010
int dp[maxn][maxn],value[maxn];
#define mm(x) memset(x,-1,sizeof(x));
int dfs(int i,int j,int num){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    else{
        dp[i][j]=max(value[i]*num+dfs(i+1,j,num+1),
        value[j]*num+dfs(i,j-1,num+1));
    }
    return dp[i][j];
}
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",value+i);
    }
    mm(dp);
    int ans=dfs(1,n,1);
    printf("%d\n",ans);
    return 0;
}
