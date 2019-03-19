#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
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
//date:19 3月 13
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;

int p,e,i,d;

int main(){
    int t=0;
    while(cin>>p>>e>>i>>d && (p!=-1)){
        t++;
        int a=23,b=28,c=33;
        int mul=a*b*c;
        int ra=b*c,rb=a*c,rc=a*b;
        int ta=ra%a,tb=rb%b,tc=rc%c;
        //ta*y1=1(mod 23) 其实不好解，真要解的话是扩展欧几里得 ta*y1+k*23=1
        //解出y1,k
        //这里我们采用试的方法
        //也有人先把它手算出来
        //其实可以预先算出来，不用每次都算
        int y1,y2,y3;
        for(int i=1;i<=a;i++){
            if((i*ta)%23==1){y1=i;break;}
        }
        for(int i=1;i<=b;i++){
            if((i*tb)%b==1){y2=i;break;}
        }
        for(int i=1;i<=c;i++){
            if((i*tc)%c==1){y3=i;break;}
        }
        //db(y1),db(y2),db(y3);
        int ans=(ra*y1*p+rb*y2*e+rc*y3*i+mul-d)%mul;
        if(ans==0) ans=mul;
        printf("Case %d: the next triple peak occurs in %d days.\n",t,ans);
    }
    
    return 0;
}