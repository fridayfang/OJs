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
//date:19 3月 03
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6+5;
ll a[maxn],sum[maxn];
int n;
stack<int> st;
int l[maxn],r[maxn];

int main(){
    sf(n);fr1(i,n){sf(a[i]);sum[i]=a[i];sum[i]+=sum[i-1];}
    st.push(0);//a[0]=sum[0]=0 stack中是下标,可保证栈不空
    a[0]=a[n+1]=-1;
    for(int i=1;i<=n+1;i++){
        //要就加入元素小于栈顶
        while(a[st.top()]>a[i]){//严格小于
            int idx=st.top();st.pop();
            r[idx]=i;
        }
        // now a[st.top()]<=a[i]
        int now=st.top();
        if(a[now]==a[i]) l[i]=l[now];
        else l[i]=now;
        st.push(i);

    }
    //
    ll ans=0;
    int tmpl=0,tmpr=2;//初始化很重要，下面可能不执行
    for(int i=1;i<=n;i++){
        int le=l[i],ri=r[i];
        //db(l[i]),db(r[i]);
        ll suma=sum[ri-1]-sum[le];
        if(suma*a[i]>ans){
            tmpl=le,tmpr=ri;
            ans=suma*a[i];
        }

    }
    printf("%lld\n",ans);
    printf("%d %d\n",tmpl+1,tmpr-1);



    
    return 0;
}