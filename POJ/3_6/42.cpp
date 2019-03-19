#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
//date:19 3月 06
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
long double a1,a2;
//float -3.4*10^38 - 3.4*10^38     input %f output %f
//double -1.7*10^308 - 1.7*10^308   input: %lf output %f
//long double -1.2*10^4932 ~1.2*10^4932
//直接用cin cout即可
int main(){
    cin>>a1>>a2;
    int x=log2(a2)/log2(a1);
    for(register int i=0;i<=9999999999;i++){
        //借评测机测试
    }
    cout<<x;
    return 0;
}