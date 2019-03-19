#include <bits/stdc++.h>
using namespace std;
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
//date:19 3月 05
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 5000 + 5;
const int maxm = 1e6+5;
int n,q;
int l[maxn],r[maxn],a[maxn];
int len[maxn];//??????????????
int dp[maxn][maxn];
int sum;//
int main(){
    cin>>n>>q;
    fr1(i,q){cin>>l[i]>>r[i];a[l[i]]++,a[r[i]+1]--;}//???
    fr1(i,n){a[i]+=a[i-1];if(a[i]>0)sum++;}//???a[],sum??q?painter????
    //sum?q?painter?????
    for(int i=1;i<=q;i++){//????painter???
        for(int j=l[i];j<=r[i];j++){
            if(a[j]==1) len[i]++;
        }
    }
    //??????????
    for(int i=1;i<=n;i++){//??2??????
        if(a[i]==2){
            int p1=0,p2=0;
            for(int j=1;j<=q;j++){
                if(l[j]<=i&&i<=r[j]){
                    if(p1==0)p1=j;
                    else p2=j;
                }
            }
            dp[p1][p2]++;//p2>p1
        }
    }
    //?????????
    int ans=0;
    for(int i=1;i<=q;i++){
        for(int j=i+1;j<=q;j++){
            ans=max(ans,sum-len[i]-len[j]-dp[i][j]);
        }
    }
    pr(ans);
    return 0;
}