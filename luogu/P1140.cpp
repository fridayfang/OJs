#include<bits/stdc++.h>
using namespace std;
#define maxn 110
char s1[maxn],s2[maxn];
int n,m;
int dp[maxn][maxn];
//dp[i][j]
int minv=-2e8;
int mp[5][5]={
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};
int help(char a){
    if(a=='A') return 0;
    if(a=='C') return 1;
    if(a=='G') return 2;
    if(a=='T') return 3;
    return 4;
}
int help2(char a,char b){
    int i=help(a);
    int j=help(b);
    return mp[i][j];
}
int main(){
    scanf("%d",&n);
    scanf("%s",s1+1);
    scanf("%d",&m);
    scanf("%s",s2+1);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+help2(s1[i],'-');
    }
    for(int j=1;j<=m;j++){
        dp[0][j]=dp[0][j-1]+help2('-',s2[j]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j]+help2(s1[i],'-'), dp[i][j-1]+help2('-',s2[j]));
           // dp[i][j]=max(dp[i][j],dp[i-1][j]+help2(s1[i],'-'));
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+help2(s1[i],s2[j]));
            ///printf("db i %d j %d dp[i][j] %d\n",i,j,dp[i][j]);
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;

}
