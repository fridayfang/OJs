#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
typedef long long ll;
const ll M=1020304067;
ll mu[maxn],l,r,mid,n,a[maxn],cnt[maxn],f[maxn],nf[maxn],inv[maxn],x,w;
ll C(ll x,ll y){
    if(y>x) return 0;
    return f[x]*nf[y]%M*nf[x-y]%M;
}
bool check(ll x){
    ll res=0;
    for(int i=1;i<maxn;i++)if(mu[i])(res+=mu[i]*C(cnt[i],x))%=M;
    res=(res+M)%M;
    return (bool)res;
}
int main(){
    inv[1]=1;for(int i=2;i<maxn;i++)inv[i]=M-(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1;
    for(int i=1;i=maxn;i++) f[i]=f[i-1]
}