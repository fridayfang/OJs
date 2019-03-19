#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
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
//date:19 3月 08
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 1e6+5;
int base=31,wlen,tlen;
ull ba[maxn],sum[maxm];
char w[maxn],t[maxm];
int solve(){
    ull whash=0;
    ba[wlen-1]=1;
    for(int i=wlen-2;i>=0;i--){
        ba[i]=ba[i+1]*base;
    }
    for(int i=0;i<wlen;i++){
        whash+=ba[i]*(w[i]-'A');
    }
    for(int i=0;i<tlen;i++){
        sum[i]+=sum[i-1]*base+t[i]-'A';
    }
    int ans=0;
    for(int j=0;j<tlen;j++){
        if(j+wlen-1>=tlen) break;
        ull subhash=0;
        if(sum[])
    }
    return ans;

}


int main(){
    int T;sf(T);
    while(T--){
        scanf("%s %s",w,t);
        wlen=strlen(w),tlen=strlen(t);
        pr(solve());
    }
    
    return 0;
}