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
//date:19 3? 11
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;

//humble number must be k2*2 or k3*3 or k5*5 or  k7*7
//??k2,k3,k5,k7????
//so we canrecord k2,k3,k5,k5 and generate the next number
//???????k2*2???k2???????
ull num[5900];
void get_val(){
    num[1]=1;int p2=1,p3=1,p5=1,p7=1;
    int m=1;
    while(m<=5849){
        num[++m]=min(min(num[p2]*2,num[p3]*3),min(num[p5]*5,num[p7]*7));
        if(num[m]==num[p2]*2)p2++;
        if(num[m]==num[p3]*3)p3++;
        if(num[m]==num[p5]*5)p5++;
        if(num[m]==num[p7]*7)p7++;
    }
}
int main(){
    int n;
    get_val();
    while(scanf("%d",&n)&&n){
        if(n%10==1&&n%100!=11)printf("The %dst humble number is %lld.\n",n,num[n]);
        else if(n%10==2&&n%100!=12)printf("The %dnd humble number is %lld.\n",n,num[n]);
        else if(n%10==3&&n%100!=13)printf("The %drd humble number is %lld.\n",n,num[n]);
        else printf("The %dth humble number is %lld.\n",n,num[n]);

    }

}