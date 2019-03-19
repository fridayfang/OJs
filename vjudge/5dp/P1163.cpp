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
const int maxn = 100 + 5;
const int maxm = 1e6+5;

int mp[maxn][maxn];
int dp[maxn];//每行每个位置的最大路径，行状态被滚动掉
//dp[i][j]=dp[i+1]

int main(){
    int n;sf(n);
    fr1(i,n){
        fr1(j,i){
            sf(mp[i][j]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(i==n) dp[j]=mp[i][j];
            else dp[j]=max(dp[j],dp[j+1])+mp[i][j];
        }
    }
    printf("%d\n",dp[1]);
    
    return 0;
}