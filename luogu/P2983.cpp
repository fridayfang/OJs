#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll unsigned long long
ll bound;
struct choco{
    ll p,c;
};
choco co[maxn];
ll n;
static bool cmp(choco c1,choco c2){
    return (c1.p<=c2.p);
}
int main(){
    scanf("%lld %lld",&n,&bound);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&co[i].p,&co[i].c);
    }
    /*
    for(int i=1;i<=n;i++){
        printf("db0 i %d price: %lld cows %lld\n",i,co[i].p,co[i].c);
    }
    */
    sort(co+1,co+1+n,cmp);
    //db
    /*
    for(int i=1;i<=n;i++){
        printf("db i %d price: %d cows %d\n",i,co[i].p,co[i].c);
    }*/
    ll res=bound;
    int idx=1;
    ll ans=0;
    while(res>=co[idx].p*co[idx].c&&idx<=n){
        ans+=co[idx].c;
        res-=co[idx].p*co[idx].c;
        idx++;
    }
    if(idx>n){
        printf("%lld\n",ans);
        return 0;
    }
    else{
        ll add=res/co[idx].p;
        ans+=add;
        printf("%lld\n",ans);
        return 0;
    }

    
}