#include <bits/stdc++.h>
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
//date:19 3月 02
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
ll l,r;
int t;
char s[1000];
int check(){
    int len=strlen(s);
    ll sum=0;
    if(s[0]=='0'){
        if(len==1){if(0<=r&&0>=l)return 0; return 2;}
        else return 1;
    }
    else{
        if(s[0]=='-'&&s[1]<='9'&&s[1]>='1'){
            sum=0;
            for(int i=1;i<=len-1;i++){
                sum=sum*10+s[i]-'0';
                //db(sum);
                
                if((0-sum)<l) return 2;
            }
            return 0;

        }
        else if(s[0]<='9'&&s[0]>='1'){
            sum=0;
            for(int i=0;i<=len-1;i++){
                sum=sum*10+s[i]-'0';
                //db(sum);
                if(sum>r) return 2;
            }
            return 0;

        }
        else return 1;
    }
}


int main(){
    scanf("%lld %lld %d",&l,&r,&t);
    fr1(i,t){
        scanf("%s",s);
        printf("%d\n",check());
    }
    
    return 0;
}