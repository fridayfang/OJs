#include <bits/stdc++.h>
using namespace std;
#define maxn 5010
int n,a[maxn],dp[maxn],path[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    int ans1=0,ans2=0;
  
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(a[i]<a[j]) dp[i]=max(dp[i],dp[j]+1);
        }
        ans1=max(ans1,dp[i]);
    }
    for(int i=1;i<=n;i++){
        if(dp[i]==1) path[i]=1;//初始化
        for(int j=1;j<i;j++){//
            if(dp[i]==dp[j]+1&& a[i]<a[j]) path[i]+=path[j];
            else if(dp[i]==dp[j]&&a[i]==a[j]) path[i]=0; //去掉重复
        }
        if(dp[i]==ans1) ans2+=path[i];
        
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
    
}