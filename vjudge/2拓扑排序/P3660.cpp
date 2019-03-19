#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
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
const int maxn = 100 + 5;
const int maxm = 1e6+5;
struct Edge{
    int u,v,nxt;
}es[4600];
int n,m;
//floyd算法
int mp[maxn][maxn];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mp[i][k]==mp[k][j]&&(mp[i][k]==1||mp[i][k]==-1)){
                    mp[i][j]=mp[i][k];
                }
            }
        }
    }

}
int main(){
    sf(n),sf(m);
    CL(mp,0x3f);
    fr1(i,m){
        int u,v;
        sf(u),sf(v);
        mp[u][v]=1;
        mp[v][u]=-1;
    }
    floyd();
    int ans=0;
    for(int i=1;i<=n;i++){
        bool check=true;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(mp[i][j]!=-1&&mp[i][j]!=1){
                check=false;
                break;
            }
            
        }
        if(check) ans++;
    }
    printf("%d\n",ans);
    return 0;
}


