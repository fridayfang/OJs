#include <bits/stdc++.h>
using namespace std;
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
#define ll long long
//author:fridayfang
//date:19 3月 06
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);

const int maxn = 2e5 + 5;
const int maxm = 1e6+5;
ll a[maxn],b[maxn];
int n,k;
struct lap{
    ll a,b,minu;//minu 表示坚持的分钟
    friend bool operator <(lap l1,lap l2){
        return l1.minu>l2.minu;//for min heap
    }
}laps[maxn];
//二分答案，然后求解
bool check(ll p){
    //db(p);
    priority_queue<lap> pq;
    for(int i=1;i<=n;i++){
        laps[i].a=a[i],laps[i].b=b[i],laps[i].minu=a[i]/b[i];//
        pq.push(laps[i]);
    }
    for(int i=1;i<k;i++){//i: minutes
        lap need=pq.top();//the laptop need charge
        pq.pop();
        need.a+=p,need.minu=need.a/need.b;
        if(need.a/need.b<k){//还需充电的入heap
            pq.push(need);
        }
        //check any remain lack of power
        if(pq.empty()){return true;}//优化
        lap need2=pq.top();
        if(need2.minu<i){//db(i),db(need2.minu);
        return false;}//无法坚持到i minutes
    }
    return true;
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    fr1(i,n)scanf("%lld",&b[i]);
    ll lo=0,hi=1e13,mid;
    while(lo<hi){
        mid=(lo+hi)>>1;
        if(!check(mid)){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(lo==1e13)printf("-1\n");
    else printf("%lld\n",lo);
    return 0;
}
