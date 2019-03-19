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

//k=(c*k)/(c+1)
//k<=(c+1) k=k-1
//   k<=2*(c+1) k=k-2

int k,c;

int main(){
    sf(k),sf(c);
    //int sub=(k+c)/(c+1);//k<=sub*(c+1) k-=sub    k<=(sub-1)*(c+1)
    //int t=(k-(sub-1)*(c+1))/sub;
    //k=k-t*sub;
    int timing=0;
    while(k!=0){
        int sub=(k+c)/(c+1);
        //db(sub);
        int t=(k-(sub-1)*(c+1)+sub-1)/sub;
        //db(t);
        k=k-t*sub;
        timing+=t;
    }
    pr(timing-1);


    
    
    return 0;
}