#include <bits/stdc++.h>
#include<cstdlib>
#include<cstdio>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define name2str(name) (#name)
#define to2(a) itoa(a,s,2)
#define db(x) cout<<#x"=["<<(x)<<"]"<<endl
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define rng(a) a.begin(),a.end()
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
//author:fridayfang
//date:19 3月 11
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int n;//islands
int mpp[20][20];
int dp[1<<17][20];//state 二进制表示dp[state][j]遍历了state状态表示的点，然后到达j的;j不在state中
//需要遍历5个点 那么dp[1111][5] 每次选择一个点(非0)--> [0001][t]初始化
char s[5];
int solve(int state,int des){
    if(state==1&&des!=0)return mpp[0][des];
    if(dp[state][des]<inf) return dp[state][des];
    for(int i=1;i<(n-1);i++){
        if(state&(1<<i)){
            dp[state][des]=min(dp[state][des],solve(state-(1<<i),i)+mpp[i][des]);
        }
    }
    return dp[state][des];
    
}
int main(){
    sf(n);
    fr0(i,n){
        fr0(j,n){
            sf(mpp[i][j]);
        }
    }
    CL(dp,inf);
    int ans=solve((1<<(n-1))-1,n-1);
    pr(ans);
    
    return 0;
}