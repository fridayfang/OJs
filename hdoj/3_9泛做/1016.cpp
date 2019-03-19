#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
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
//date:19 3月 09
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int n;
int isp[200];
int vis[200];
void get_prime(){
    for(int i=2;i<200;i++) isp[i]=1;
    for(int i=2;i<200;i++){
        if(isp[i]){
            for(int j=i*i;j<200;j+=i){
                isp[j]=0;
            }
        }
    }
    /*
    for(int i=2;i<200;i++){
        if(isp[i])printf("%d ",i);
    }
    printf("\n");
    */
}
//vis[1]=1
vector<int> ring;
void prv(vector<int> v){
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1)printf("%d",v[i]);
        else printf("%d ",v[i]);
    }
    
    printf("\n");
    /*
    for(int i=v.size()-1;i>=0;i--){
        printf("%d ",v[i]);
    }
    printf("\n");
    */
}
void dfs(int cur,int cnt){//
    if(cnt==n&&isp[cur+1]){prv(ring);}
    for(int i=1;i<=n;i++){
        if(!vis[i]&&isp[i+cur]){
            vis[i]=1;
            ring.push_back(i);
            dfs(i,cnt+1);
            ring.pop_back();
            vis[i]=0;
        }
    }


}

int main(){
    get_prime();
    int cnt=0;
    while(~scanf("%d",&n)){
        cnt++;
        CL(vis,0);
        vis[1]=1;ring.push_back(1);
        printf("Case %d:\n",cnt);
        dfs(1,1);
        printf("\n");
        ring.pop_back();
    }
    
    return 0;
}