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
int a[maxn];
int l[maxn],r[maxn];
int n;
stack<int> st;//存标号
int main(){
    while(scanf("%d",&n)&&n){
        CL(a,0);fr1(i,n) sf(a[i]);
        a[0]=a[n+1]=-1;st.push(0);
        for(int i=1;i<=n+1;i++){
            while(!st.empty()&&a[st.top()]>a[i]){///严格小于
                r[st.top()]=i;st.pop();
            }
            //a[st.top()]<=a[i]
            if(a[st.top()]==a[i]) l[i]=l[st.top()];//严格小于
            else l[i]=st.top();
            st.push(i);

        }
        ll ans=0;
        int le=0,ri=2;
        for(int i=1;i<=n;i++){
            //db(l[i]),db(r[i]);
            if((ll)a[i]*(r[i]-l[i]-1)>ans){
                ans=(ll)a[i]*(r[i]-l[i]-1);
                le=l[i],ri=r[i];
            }
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}