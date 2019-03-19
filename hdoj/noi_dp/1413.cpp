#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define name2str(name) (#name)
#define db(x) cout<<#x"=["<<(x)<<"]"<<endl
#define to2(a,n) for(int i=n-1;i>=0;i--){if(a&(1<<i))printf("1");else printf("0");}
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
const int maxn=1<<12;
ll dp[2][maxn];
int n,m;
int cur;
void dfs(int pos,int nu,int z){
    if(pos==m){//处理第m个位置的时候本行已经处理完
        dp[cur][nu]+=dp[cur^1][z];
        return ;
    }
    if(!(z&(1<<pos)))//如果上一行pos位置是0,那么本行pos位置必须竖着放
    dfs(pos+1,nu|(1<<pos),z);
    else {
        if(pos &&(!(nu&(1<<pos-1))))//判断是否可以横着放
        dfs(pos+1,nu|(1<<pos)|(1<<pos-1),z);
        dfs(pos+1,nu,z);//不放木块，留着下一排去解决
    }
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        cur=0;
        int mask=(1<<m)-1;//可能的状态总数
        CL(dp,0);
        dp[0][mask]=1;//第一排有效状态时mask
        for(int i=1;i<=n;i++){
            cur^=1;
            CL(dp[cur],0);
            for(int j=0;j<=mask;j++){
                if(dp[cur^1][j])dfs(0,0,j);
            }
        }
        printf("%lld\n",dp[cur][mask]);
    }
    
    return 0;
}