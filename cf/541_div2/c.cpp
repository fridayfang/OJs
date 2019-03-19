#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 100 + 5;
const int maxm = 1e6+5;
//author:fridayfang
//date:19 2月 23
//global varibles
int hei[maxn];
int ans[maxn];
int n;
int main(){
    sf(n);
    for(int i=0;i<n;i++){
        sf(hei[i]);
    }
    sort(hei,hei+n);
    for(int i=0;i<n;i+=2){
        int a=i>>1;
        int b=n-1-a;
        ans[a]=hei[i];
        if(i+1<n) ans[b]=hei[i+1];

    }
    fr0(i,n){
        printf("%d ",ans[i]);
    }
    
    
    return 0;
}