#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=50010;
int miu[maxn],prime[maxn],tot,s[maxn],n;
bool mark[maxn];
void pre(int n){//预处理
    miu[1]=1;//莫比乌斯函数
    for(int i=2;i<=n;i++){
        if(!mark[i]) miu[i]=-1,prime[++tot]=i;//素数
        for(int j=1;j<=tot&&i*prime[j]<=n;j++){
            //枚举已知素数的倍数(i倍)
            mark[i*prime[j]]=1;//素数筛
            miu[i*prime[j]]=-miu[i];//i*prime[j]相对于i增加了一个本质1不同的素数
            if(i%prime[j]==0){miu[i*prime[j]]=0;break;}//平方因子的情况,用最小因子筛
        }
    }
    for(int i=1;i<=n;i++)s[i]=s[i-1]+miu[i];//前缀和
}
ll solve(int n,int m){
    ll ans=0;int pos=0;
    for(int i=1;i<=min(n,m);i=pos+1){
        pos=min(n/(n/i),m/(m/i));
        ans+=(ll)1*(s[pos]-s[i-1])*(n/i)*(m/i);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    pre(50000);
    for(int i=1;i<=n;i++){
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        a--;c--;a/=k;b/=k;c/=k;d/=k;
        printf("%lld\n",solve(b,d)-solve(b,c)-solve(a,d)+solve(a,c));
    }
    return 0;
}