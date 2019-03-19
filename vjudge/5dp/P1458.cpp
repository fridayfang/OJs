#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 3月 01
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e3 + 5;
const int maxm = 1e6+5;
char s1[maxn],s2[maxn];
int dp[maxn][maxn];
int solve(int x,int y){
    if(x<0||y<0) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    if(x==0&&y==0&&s1[x]!=s2[y]){dp[x][y]=0; return 0;}
    if(x==0&&y==0&&s1[x]==s2[y]){dp[x][y]=1;return 1;}
    if(s1[x]==s2[y]){
        dp[x][y]=max(dp[x][y],solve(x-1,y-1)+1);
    }
    else{
        dp[x][y]=max(solve(x-1,y),solve(x,y-1));
    }
    //printf("solve:%d %d %d\n",x,y,dp[x][y]);
    return dp[x][y];  

}


int main(){
    while(~scanf("%s %s",s1,s2)){
        CL(dp,-1);
        int len1=strlen(s1),len2=strlen(s2);
        int ans=solve(len1-1,len2-1);
        printf("%d\n",ans);
    }
    
    return 0;
}