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
const int maxn = 1e4 + 5;
const int maxm = 1e6+5;
//author:fridayfang
//date:19 2月 23
//global varibles

int solve(int a1,int b1,int a2,int b2){
    //including a1:b1
    if(a1==b1&&a2==b2) return a2-a1;
    if(a1==b1) return min(a2,b2)-a1+1;
    else{
        int nex=max(a1,b1);
        if(min(a2,b2)<nex) return 0;
        if(a2==b2) return a2-nex;
        else return min(a2,b2)-nex+1;
    }

}
struct scor{
    int a,b;
}sc[maxn];

int n;
int main(){
    sf(n);
    int a,b;
    //db(solve(0,0))
    fr1(i,n){
        sf(sc[i].a),sf(sc[i].b);
    }
    int ans=0;
    fr1(i,n){
        ans+=solve(sc[i-1].a,sc[i-1].b,sc[i].a,sc[i].b);

    }
    ans+=(sc[n].a==sc[n].b);
    pr(ans);
    
    
    return 0;
}