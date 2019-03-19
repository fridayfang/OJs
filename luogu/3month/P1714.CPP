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
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 5e5 + 5;
const int maxm = 1e6+5;
int sum[maxn];
int dp[maxn];
int n,M;
deque<int> q;
int main(){
    sf(n),sf(M);
    fr1(i,n){sf(sum[i]);sum[i]+=sum[i-1];}
    //dp[i]=sum[i]-min{sum[k]} k:i-1..i-M
    for(int i=0;i<n;i++){
        if(!q.empty()&&i>=M&&q.front()==sum[i-M]) q.pop_front();
        while(!q.empty()&&q.back()>sum[i]) q.pop_back();
        q.push_back(sum[i]);
        int tmp=q.front();
        dp[i+1]=max(dp[i+1],sum[i+1]-tmp);
    }
    int ans=0;
    fr1(i,n) ans=max(ans,dp[i]);
    pr(ans);
    return 0;
}