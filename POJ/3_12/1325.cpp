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
//date:19 3月 12
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e2 + 5;
const int maxm = 1e6+5;
int n,m,k;//n for A
int linker[maxn];//record the matching of B
int used[maxn];//record the dfs situation of B
//二分图(无向)最小点集覆盖
int mpp[maxn][maxn];
bool dfs(int u){
    for(int i=1;i<m;i++){
        if(mpp[u][i]&&!used[i]){
            used[i]=1;
            if(linker[i]==-1||dfs(linker[i])){
                linker[i]=u;
                return true;
            }
        }
    }
    return false;
}


int main(){
    while(scanf("%d",&n)&&n){
        sf(m),sf(k);
        CL(linker,-1),CL(mpp,0);
        fr1(i,k){
            int id,u,v;
            sf(id),sf(u),sf(v);
            if(u==0||v==0)continue;
            mpp[u][v]=1;
        }
        int ans=0;
        for(int i=1;i<n;i++){
            CL(used,0);
            if(dfs(i)) ans++;
        }
        pr(ans);
    }
    
    return 0;
}