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
//date:19 3月 04
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1000 + 5;
const int maxm = 1e5+5;
int a[maxn],n;
int has[maxm];
int solve(){
    int mm=0;
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        for(int j=n;j>i;j--){
            int sum=a[i]+a[j];
            int ans=0;
            for(int k=i;k<=j;k++){
                int t=sum-a[k];
                if(has[t]&&t!=a[k]) ans++;

            }
            mm=max(mm,ans);
        }
    }
    return mm;
}

int main(){
    sf(n);fr1(i,n){sf(a[i]);has[a[i]]=1;}
    pr(solve()/2);
    
    return 0;
}