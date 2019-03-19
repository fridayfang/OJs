#include <bits/stdc++.h>
using namespace std;
//author:fridayfang
//date:19 2月 24
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int n;


int main(){
    
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sf(n);
    int t;
    int cnt1=0,cnt2=0;
    fr0(i,n){
        sf(t);
        if(t>0) cnt1++;
        else if(t<0) cnt2++;
    } 
    if(cnt1*2>=n){
        printf("1\n");
    }
    else if(cnt2*2>=n){
        printf("-1\n");
    }
    else{
        printf("0\n");
    }

    
    return 0;
}