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
//date:19 3月 02
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int a[maxn];
int n,k;
deque<int> q1;
deque<int> q2;
int main(){
    sf(n),sf(k);
    fr1(i,n) sf(a[i]);
    for(int i=1;i<=n;i++){
        if(!q2.empty()&&i>=k&&a[i-k]==q2.front()) q2.pop_front();
        while(!q2.empty()&&q2.back()>a[i]) q2.pop_back();
        q2.push_back(a[i]);
        if(i>=k) printf("%d ",q2.front());
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        if(!q1.empty()&&i>=k&&a[i-k]==q1.front()) q1.pop_front();
        while(!q1.empty()&&q1.back()<a[i]) q1.pop_back();
        q1.push_back(a[i]);
        if(i>=k) printf("%d ",q1.front());
    }

    return 0;
}