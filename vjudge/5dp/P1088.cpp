#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define rng(a) a.begin(),a.end()
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
//author:fridayfang
//date:19 3月 01
const int maxn = 100 + 5;
const int maxm = 1e6+5;
int mp[maxn][maxn];
int dp[maxn][maxn];
int n,m;
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int get(int i,int j){
    if(dp[i][j]!=-1) return dp[i][j];
    bool tag=false;//能否被更新
    for(int k=0;k<4;k++){
        int x=i+mv[k][0],y=j+mv[k][1];
        if(x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]<mp[i][j]){
            tag=true;
            dp[i][j]=max(dp[i][j],get(x,y)+1);
        }
    }
    if(!tag){dp[i][j]=1;return 1;}//周围点都高于<i,j> 返回实际是1
    else return dp[i][j];
}
int main(){
    sf(n);sf(m);
    fr1(i,n)fr1(j,m)sf(mp[i][j]);
    CL(dp,-1);
    int ans=0;
    fr1(i,n)
    fr1(j,m){
        ans=max(ans,get(i,j));
        //printf("db dp %d %d %d mp %d\n",i,j,dp[i][j],mp[i][j]);
    }

    printf("%d\n",ans);
    return 0;
}