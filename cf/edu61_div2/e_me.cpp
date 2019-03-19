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
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
ll a[10];
ll v;
ll dp[maxn];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int getlcm(int a,int b){
    return a*b/gcd(a,b);
}
//lcm(1,2...8)=840
int main(){
    ll sum=0;
    int lcm=1;
    cin>>v;fr1(i,8){cin>>a[i];sum+=a[i]*i;}
    //db(lcm);
    if(sum<=v){cout<<sum<<endl;return 0;}
    ll ans=0;//记录已加和
    ll res=v;//记录还需凑成的容积
    for(int i=1;i<=8;i++){
        ll add=min(a[i],res/i);//记录所需和剩余的较小值
        ll radd=max(add-(840),0);//最多留下840个items
        ans+=i*radd;
        res-=i*radd;
        a[i]=a[i]-radd;
        //db(a[i]);
    }
    //db(ans),db(res);
    //经过处理所有次数不超过100
    //也保证了res不会超过840*(1+2+3+..+8)=2e4
    dp[0]=0;
    ll maxcap=0;
    for(int i=1;i<=8;i++){//complexity:2e4*8*840=1e8
        for(ll j=res;j>=0;j--){
            for(int k=0;k<=a[i];k++){
                if(j>=k*i)dp[j]=max(dp[j],dp[j-k*i]+k*i);//空间j最大能装的容积
                else break;
            }
        }
    }
    
    ans+=dp[res];
    cout<<ans<<endl;
    return 0;
}