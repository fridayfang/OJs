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
//date:19 3月 17
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;

int a[maxn];
int t,n;

int main(){
    sf(t);
    while(t--){
        sf(n);
        int ans=0;
        for(int i=1;i<=n;i++){
            sf(a[i]);
            if(a[i]==0){
                if(i>=2&&i<=n-1&&a[i-1]==0&&a[i+1]==0){a[i]=1;ans++;}
                else ans+=min(i-1,n-i);
            }
        }
        if(n==1&&a[1]==0)ans++;
        else{
            if(a[1]==0) ans++;
            if(a[n]==0) ans++;
        }
        pr(ans);
    }
    
    return 0;
}