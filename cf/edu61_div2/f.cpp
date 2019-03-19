#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
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
//date:19 3月 06
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 500 + 5;

const int N=505;
int dp[N][N];
string s;
int n;
int call(int lft,int rgt){//区间dp
    if(lft>rgt) return 0;
    if(lft==rgt){return 1;}
    if(dp[lft][rgt]!=-1)return dp[lft][rgt];
    int ans=call(lft+1,rgt)+1;
    for(int nxt=lft+1;nxt<=rgt;nxt++){
        if(s[nxt]==s[lft]){
            ans=min(ans,call(lft+1,nxt-1)+call(nxt,rgt));
        }
    }
    return dp[lft][rgt]=ans;
}
int main(){
    CL(dp,-1);cin>>n>>s;
    int ans=call(0,n-1);
    cout<<ans;
}