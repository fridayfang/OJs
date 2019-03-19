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
const int maxn = 2e5 + 5;
const int maxm = 1e6+5;
int a[maxn],dp[maxn];
deque<int> q;

int main(){
    int n,l,r;sf(n),sf(l),sf(r);
    int len=r-l+1;
    fr0(i,n) sf(a[i]);
    fr1(i,n) dp[i]=-inf;
    dp[0]=0;
    for(int i=0;i<=n;i++){
        if(!q.empty()&&i>=len&&q.front()==dp[i-len]) q.pop_front();
        while(!q.empty()&&q.back()<dp[i]) q.pop_back();
        q.push_back(dp[i]);
        int tmp=q.front();
        //db(tmp);
        if(i+l<=n){dp[i+l]=tmp+a[i+l];}
    }
    int ans=-inf;
    //for(int i=0;i<=n;i++) db(dp[i]);
    for(int i=n-r;i<=n;i++) ans=max(ans,dp[i]);
    pr(ans);
    
    return 0;
}