#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
//date:19 3月 02
const double esp=1e-8;
const int mod=19260817;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int dp[1010][1010];
int mp[1010][1010];
void solve(){
    CL(dp,0);
    dp[0][0]=1;
    for(int i=1;i<=1000;i++){
        for(int j=0;j<=i;j++){
            if(j==0){dp[i][j]=1;continue;}
            dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
        }
    }
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            
            mp[i][j]=(mp[i][j-1]%mod+mp[i-1][j]%mod-mp[i-1][j-1]%mod+mod+dp[i][j]%mod)%mod;
        }
    }
}



int main(){
    int q;sf(q);
    solve();
    fr0(t,q){
        int n,m;sf(n),sf(m);
        printf("%d\n",mp[m][n]);
    }
    
    return 0;
}