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
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int a[1010],n,k;
int tag[1010];

int b[1010]; 
int cnt;
void get_min(){
    int mi=inf;
    for(int i=1;i<=k;i++){
        mi=min(a[i],mi);
    }
    for(int i=1;i<=k;i++){
        a[i]=a[i]-mi;
        if(a[i]==0){cnt++;swap(a[i],a[cnt+k]);}
    }
    for(int i=1;i<=n;i++){
        int tmp=(int)(100*cnt/(n+0.0)+0.5);
        db(tmp);
        if(a[i]!=0&&a[i]+mi>tmp) tag[i]=true;
    }


}


int main(){

    sf(n),sf(k);
    fr1(i,n){sf(a[i]);b[i]=a[i];}
    int ans=0;
    for(int i=1;i<=n;i++){
        get_min();
    }
    for(int i=1;i<=n;i++){
        if(tag[i]) ans++;
    }
    pr(ans);
 
    return 0;
}