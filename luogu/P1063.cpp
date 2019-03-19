#include<bits/stdc++.h>
using namespace std;
#define maxn 110
int a[maxn];
int dp[maxn<<1][maxn<<1];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        a[i+n]=a[i];
    }

    //dp[i][i]=0
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=2*n;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[(j+1)]);
            }
            //printf("db i %d j %d dp[i][j] %d\n",i,j,dp[i][j]);
        }
    }
    int maxv=0;
    for(int i=1;i<=n;i++){
        maxv=max(maxv,dp[i][i+n-1]);
    }
    printf("%d\n",maxv);
    return 0;
}