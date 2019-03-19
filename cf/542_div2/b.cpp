#include <bits/stdc++.h>
using namespace std;
//author:fridayfang
//date:19 2月 24
//global varibles
#define ll long long
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e5 + 5;
const int maxm = 1e6+5;
int cake[maxn<<1],n;
struct pos{
    int p1,p2;
    bool t1,t2;
}ps[maxn];


int main(){
    
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sf(n);
    CL(ps,0);
    int t;
    for(int i=0;i<n*2;i++){
        sf(cake[i]);
        if(ps[cake[i]].t1){
            ps[cake[i]].p2=i;
            ps[cake[i]].t2=true;
        }
        else{
            ps[cake[i]].p1=i;
            ps[cake[i]].t1=true;
        }
    }
    //printf("%d %d",ps[1].p1,ps[1].p2);

    int begin0=0,begin1=0,want=1;
    ll step=0;
    //printf("want %d %d\n",want,n);
    /*for(int i=1;i<=n;i++){
        printf("db %d %d\n",ps[i].p1,ps[i].p2);
    }
    */
    while(want<=n){
        int p1=ps[want].p1,p2=ps[want].p2;
        //printf("db %d %d \n",begin,p1);
        ll ans1=abs(p1-begin0)+abs(p2-begin1);
        ll ans2=abs(p1-begin1)+abs(p2-begin0);
        if(ans1<ans2){
            begin0=p1,begin1=p2;
            step+=ans1;
        }
        else{
            begin0=p2,begin1=p1;
            step+=ans2;
        }
        want++;
    }

    
    printf("%lld\n",step);
    
    
    return 0;
}