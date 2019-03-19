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
const int maxn = 200 + 5;
const int maxm = 1e6+5;
int n,m;
int mpp[maxn][maxn];//mp[i][j] means cow i like stall j
int used[maxn];//used[i] for cow i
int linker[maxn];//linker[i] for stall if -1 not match
//used[i],linker[i],i????????
int dfs(int u){// ????dfs()??????
    for(int i=1;i<=m;i++){
        if(mpp[u][i]&&!used[i]){
            used[i]=1;
            if(linker[i]==-1||dfs(linker[i])){
                linker[i]=u;
                return 1;
            }
        }
    }
    return false;
}
int main(){
    while(~scanf("%d %d",&n,&m)){
        CL(mpp,0);
        fr1(i,n){
            int num,v;sf(num);
            fr1(j,num){sf(v);mpp[i][v]=1;}
        
        }
        //build ok
        int ans=0;
        CL(linker,-1);
        for(int i=1;i<=n;i++){
            CL(used,0);
            if(dfs(i)) ans++;//??dfs????????i???,???????????????????
        }
        pr(ans);
    }
    
    return 0;
}