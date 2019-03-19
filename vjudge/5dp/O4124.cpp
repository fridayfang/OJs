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
const int maxn = 1<<16;
const int maxm = 1e6+5;
int N;
int mp[17][17];
//dp[i][j] travel i points and reach point j 
//dp[i][j]=min(dp[i-1][k]+cost[k][j]) k!=i//需要保证经历的前i-1个点不包括j
//那么可以用状压dp，即用数字的二进制位表示哪些point被选取
//简便写法可用记忆化搜索
int dp[maxn][17];
int get(int i,int j){
    if(i!=1&&j==1){return dp[i][j]=inf;}
    if(i==1&&j!=1){return dp[i][j]=inf;}
    if(dp[i][j]!=inf) return dp[i][j];
    if(i==1&&j==1){dp[i][j]=0;return 0;}//起点
    for(int k=1;k<=N;k++){//枚举倒数第二个点
        if(k==j) continue;
        if(i&(1<<(k-1))) dp[i][j]=min(dp[i][j],get(i-(1<<(j-1)),k)+mp[k][j]);
    }
    return dp[i][j];
}

int main(){
    while(~sf(N)){
        fr1(i,N){
            fr1(j,N) sf(mp[i][j]);
        }
        CL(dp,inf);
        int des=(1<<N)-1;
        printf("%d\n",get(des,N));

        
    }

    
    return 0;
}