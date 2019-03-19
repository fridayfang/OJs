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
//date:19 3月 03
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 2e6 + 5;
const int maxm = 1e6+5;
//dp[k]=min(sum[j])-sum[k-1]    j=[k...n+k-1]
int n;
int a[maxn];
int dp[maxn];
deque<int> q;
int main(){
    sf(n);
    fr1(i,n){sf(a[i]);a[i+n]=a[i];};
    fr1(i,2*n){a[i]+=a[i-1];}
    for(int i=1;i<=2*n;i++){
        if(!q.empty()&&i>n&&q.front()==a[i-n]) q.pop_front();
        while(!q.empty()&&q.back()>a[i]) q.pop_back();
        q.push_back(a[i]);
        //db(a[i]);
        int tmp=q.front();
        //min(sum[i-n+1]....sum[i])
        if(i>=n){dp[i-n+1]=tmp-a[i-n];}
    }
    int ans=0;
    fr1(i,n){if(dp[i]>=0) ans++;}
    pr(ans);
    
    return 0;
}