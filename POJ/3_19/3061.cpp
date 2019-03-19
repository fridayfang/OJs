#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
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
//date:19 3月 19
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6+5;

int a[maxn],sum[maxn];
int S,n;
int solve(){
    int i=1,j=1;
    int tmp=a[1];
    int minlen=inf;
    //i>j means no elements
    while(j<=n){
        while(tmp<S&&j<=n){
            //j++;tmp=sum[j]-sum[i-1];
            j++;tmp+=a[j];
        }
        if(j>n)break;
        while(tmp>=S&&i<=j){
            //i++;tmp=sum[j]-sum[i-1];
            minlen=min(minlen,j-i+1);
            tmp-=a[i];i++;
        }
    }
    return minlen<inf?minlen:0;
}


int main(){
    fast;int t;cin>>t;
    while(t--){
        cin>>n>>S;
        CL(a,0);
        fr1(i,n){cin>>a[i];sum[i]=sum[i-1]+a[i];}
        cout<<solve()<<endl;
    }
    
    return 0;
}