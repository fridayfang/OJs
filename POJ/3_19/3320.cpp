#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
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
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;

int n;
map<int,int> mp;//
int a[maxn];
int cnt;
int solve(){
    int i=1,j=1;
    int ans=1;
    mp[1]=1;
    int minl=inf;
    while(i<=j&&j<=n){
        while(ans<cnt){
            j++;int t=a[j];
            if(mp.count(t)==0){mp[t]=1;ans++;}
            else{mp[t]--;}
        }
        db(i),db(j);
        while(ans>=cnt&&i<=j){
            minl=min(minl,j-i+1);
            int t=a[i];i++;
            mp[t]--;
            if(mp[t]==0){ans--;}
        }

    }
    return minl;
}

int main(){
    fast;cin>>n;
    fr1(i,n)cin>>a[i];
    cout<<solve()<<endl;
    
    return 0;
}