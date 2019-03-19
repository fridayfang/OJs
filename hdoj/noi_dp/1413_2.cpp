#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define name2str(name) (#name)
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
/*
dfs版：

for(i = 2; i <= h; i++)//枚举行数

 

　　for(j = 0; j < (1<<w); j++)//枚举上一行的状态

 

　　　　if(...) dfs(...)//如果上一行该状态方法数不为0，则dfs遍历该行可行状态

遍历的方法很巧妙：假设所枚举到的上一行状态为s，则将s每一位都取反便是该行的一种可行状态。
因为，如果s的某一位是0，说明这是一竖放砖块的上半部分，取反后恰好就是下半部分对应的1；如果s某一位是1，取反后是0，这当然也是可行的。

又由于当s某一位是1时，下一行对应的位可以是0或者1（若是1则必然是横放的，需要连续两位状态都是1）。
所以在dfs的过程中需要遍历所有两个0相邻的情况，将他们置为1。当dfs的下标pos到达最后一位（即pos=w）时，说明该状态是可行的，就将该状态的dp值加上上一行状态s的dp值。
因此，每次dfs之前都需要暂时存储下上一行状态s的dp值。
*/

ll dp[1<<12][13],tem,h,w;
void dfs(int row,int state,int pos){
    if(pos==w){
        dp[state][row]+=tem;return ;
    }
    dfs(row,state,pos+1);
    if(pos<=w-2&&!(state&(1<<pos))&&!(state &(1<<(pos+1))))
    dfs(row,state|1<<pos|1<<(pos+1),pos+2);
}
/*
void dfs(int row,int state,int pos){
    if(pos==w){
        dp[state][row]+=tem;return;
    }
    dfs(row,state,pos+1);
    if(pos<=w-2&&!(state&(1<<pos))&&!(state&(1<<(pos+1))))
    dfs(row,state|1<<pos|1<<(pos+1),pos+2);
}
*/

int main(){
    while(~scanf("%d %d",&h,&w)&&h&&w){
        if((h*w)%2){
            printf("0\n");continue;
        }
        if(h<w)swap(h,w);
        memset(dp,0,sizeof(dp));
        tem=1;dfs(1,0,0);
        for(int i=2;i<=h;i++){
            for(int j=0;j<(1<<w);j++){
                if(dp[j][i-1]){
                    tem=dp[j][i-1];
                    dfs(i,~j&((1<<w)-1),0);
                }
            }
        }
        printf("%lld\n",dp[(1<<w)-1][h]);
    }
    return 0;
    
    return 0;
}