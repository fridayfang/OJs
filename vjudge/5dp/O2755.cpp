#include <bits/stdc++.h>
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
//date:19 2月 28
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int a[30],n;
int ans=0;
int dfs(int pos,int cur){
    if(cur==40) return 1;
    if(pos>n) return 0;
    int sol=0;
    //选择
    sol+=dfs(pos+1,cur+a[pos]);
    sol+=dfs(pos+1,cur);
    return sol;
}



int main(){
    sf(n);fr1(i,n)sf(a[i]);
    printf("%d\n",dfs(1,0));
    return 0;
}