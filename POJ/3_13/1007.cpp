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
//date:19 3月 13
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;

int n,m;
string strs[200];
int calc(string s){
    int ans=0;
    int len=s.length();
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(s[i]>s[j]) ans++;
        }
    }
    return ans;
}
bool cmp(string s1,string s2){
    return calc(s1)<calc(s2);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>strs[i];
    stable_sort(strs,strs+m,cmp);
    for(int i=0;i<m;i++)cout<<strs[i]<<endl;
    return 0;
}