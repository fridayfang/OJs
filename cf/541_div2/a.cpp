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
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
//author:fridayfang
//date:19 2? 23
//global varibles

int w1,h1,w2,h2;

int main(){
    sf(w1),sf(h1),sf(w2),sf(h2);
    int len=(w1+h1)*2+(w2+h2)*2-2*min(w1,w2);
    pr(len+4);

    
    return 0;
}