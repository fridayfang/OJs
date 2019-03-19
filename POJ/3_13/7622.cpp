#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
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
//date:19 3月 13
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6+5;
//逆序对 mergesort 解决
ll ans; int n;
int a[maxn];
int b[maxn];//for merge
void msort(int l,int r){
    if(l==r) return ;
    int mid=(l+r)>>1;
    msort(l,mid);msort(mid+1,r);
    int i=l,j=mid+1;
    //a[i]>a[j] ans+=(mid-i+1) a[j+1]??
    //a[i]<a[j]
    //db(ans);
    while(i<=mid&&j<=r){
        if(a[i]>a[j]){
            //db(i),db(j),db(mid);
            ans+=(mid-i+1);j++;}
        else{i++;}
    }
    //db(ans);
    //merge
    int pos=l;
    i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i]>a[j]){b[pos++]=a[j];j++;}
        else {b[pos++]=a[i];i++;}
    }
    while(i<=mid){b[pos++]=a[i];i++;}
    while(j<=r){b[pos++]=a[j];j++;}
    for(int i=l;i<=r;i++)a[i]=b[i];
    
}



int main(){
    sf(n);
    for(int i=0;i<n;i++)sf(a[i]);
    msort(0,n-1);
   printf("%lld\n",ans);
    //for(int i=0;i<n;i++)printf("%d ",a[i]);
    
    return 0;
}