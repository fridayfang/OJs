#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<stdlib.h>
using namespace std;
#define max(a,b) (a) > (b) ? (a) : (b)  
#define min(a,b) (a) < (b) ? (a) : (b)
#define ll long long
#define eps 1e-10
#define MOD 1000000007
#define N 16
#define M 1<<16
#define inf 1e12
ll n,m;
ll dp[N][M];
ll state_true[M];
ll total;
ll nowTotal;
bool judge(ll s){
    ll ans=0;
    while(s>0){
        if((s&1)==1){
            ans++;
        }
        else{
            if((ans&1)==1){
                return false;
            }
            ans=0;
        }
        s>>=1;
    }
    if((ans&1)==1)
       return false;
     return true;
}
void init(){
     total=(1<<16);
    for(ll S=0;S<total;S++){
        if(judge(S)){
            state_true[S]=1;
        }
    }
}
bool check(ll s1,ll s2){
    if( (s1 | s2) != (nowTotal-1) ){
        return false;
    }
    return state_true[s1&s2];
}
int main()
{
    init();
    while(scanf("%I64d%i64d",&n,&m)==2){
        if(n==0 && m==0) break;
        
        nowTotal=(1<<m);
        memset(dp,0,sizeof(dp));
        for(ll S=0;S<nowTotal;S++){
            if(state_true[S]){
                dp[0][S]=1;
            }
        }
        for(ll i=1;i<n;i++){
            for(ll S1=0;S1<nowTotal;S1++){
                for(ll S2=0;S2<nowTotal;S2++){
                    if(check(S1,S2)){
                        dp[i][S1]+=dp[i-1][S2];
                    }
                }
            }
        }
        printf("%I64d\n",dp[n-1][nowTotal-1]);
    }
    return 0;
}