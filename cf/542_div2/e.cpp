#include <bits/stdc++.h>
using namespace std;
//author:fridayfang
//date:19 2月 26
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 5000 + 5;
const int maxm = 20000+5;

int dis[maxn];//记录源站点到目的站点最近的距离
int num[maxn];//记录站点糖的数量;
//从站点i除法运完站点j的糖的时间
//(j-i+n)%n+n*(num[j]-1)+dis[j]
//枚举j得到最大时间则是所求
int n,m;


int main(){
    sf(n),sf(m);
    fr1(i,m){
        int a,b;
        sf(a),sf(b);
        if(num[a]){
            dis[a]=min(dis[a],(b-a+n)%n);
        }
        else dis[a]=(b-a+n)%n;
        num[a]++;
    }
    fr1(i,n){
        int ans=0;
        fr1(j,n){
            ans=max(ans,(j-i+n)%n+n*(num[j]-1)+dis[j]);
        }
        printf("%d ",ans);
    }
    

    return 0;
}