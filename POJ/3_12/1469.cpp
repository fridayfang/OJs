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

int P,N;
int linker[305],vis[305];//for strudent
int mpp[maxn][305];
bool dfs(int u){
    for(int i=1;i<=N;i++){
        if(mpp[u][i]&&!vis[i]){
            vis[i]=1;
            if(linker[i]==-1||dfs(linker[i])){
                linker[i]=u;
                return true;
            }
        }
    }
    return false;
}



int main(){
    int t;sf(t);
    while(t--){
        CL(linker,-1),CL(mpp,0);
        sf(P),sf(N);
        fr1(i,P){
            int v,num;sf(num);
            while(num--){sf(v);mpp[i][v]=1;}

        }
        int ans=0;
        for(int i=1;i<=P;i++){
            CL(vis,0);
            if(dfs(i)) ans++;
        }
        if(ans==P)printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}