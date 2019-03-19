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
//date:19 3月 13
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn =1e10 + 5;
const int maxm = 1e6+5;
int nisp[maxn];
vector<ll> primes;
void get_prime(){
    for(ll i=2;i<maxn;i++){
        if(!nisp[i]){
            primes.push_back(i);
            //db(i);
            for(ll j=i*i;j<(ll)
            maxn;j+=i){
                nisp[j]=1;
            }
        }
    }

}
void solve(ll num){
    for(int i=0;i<(int)primes.size();i++){
        //db(primes[i]);

        if(num%primes[i]==0){

            printf("%d ",primes[i]);
        }
    }
}


int main(){
    get_prime();
    ll num=437338199;
    solve(num);

    return 0;
}
