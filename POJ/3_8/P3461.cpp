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
//date:19 3月 08
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 1e6+5;
char w[maxn],t[maxm];
int nxt[maxn];
int lenw,lent;
//kmp
void get_next(){
    nxt[0]=-1;
    int i=0,j=-1;//j used for match self
    while(i<lenw){
        if(j==-1||w[i]==w[j]){
            i++,j++;
            nxt[i]=j;//会处理到i=strlen(w)
        }
        else j=nxt[j];
    }
}
int kmp(){
    int ans=0;
    int i=0,j=0;//i for t,j for w
    while(i<lent&&j<lenw){
        if(j==-1||t[i]==w[j]){
            i++,j++;
        }
        else{
            j=nxt[j];
        }
        if(j==lenw){
            ans++;
            j=nxt[j];
        }
    }
    return ans;
}


int main(){
    //freopen("in.txt","r",stdin);
    int n;sf(n);
    while(n--){
        scanf("%s",w);
        scanf("%s",t);
        lenw=strlen(w),lent=strlen(t);
        get_next();
        pr(kmp());
    }

    return 0;
}
