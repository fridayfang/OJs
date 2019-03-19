#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
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
//date:19 3月 08
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e2 + 5;
const int maxm = 1e6+5;
char be[maxn],af[maxn];
char be2[maxn],af2[maxn];
char s1[maxn],s2[maxn];
char addb[maxn],addf[maxn];
void convert(char *s,char* b,char* a){
    int len1=strlen(s);
    int pos;
    fr0(i,len1){if(s[i]=='.'){pos=i;break;}}
    int i=0;
    for(int k=pos-1;k>=0;k--){
        b[i++]=s[k];
    }
    b[i]='\0';i=0;
    for(int k=pos+1;k<len1;k++){
        a[i++]=s[k];
    }
    a[i]='\0';
}


int main(){
    scanf("%s",s1);
    scanf("%s",s2);
    int len1=strlen(s1),len2=strlen(s2);
    int p1,p2;
    convert(s1,be,af),convert(s2,be2,af2);
    //加小数
    int carry=0;
    int l1=strlen(af),l2=strlen(af2);
    if(l1<l2){swap(af,af2),swap(l1,l2);}
    for(int j=l1-1;j>=0;j--){
        if(j>=l2) addf[j]=af[j];
        else{
            int sum=af[j]-'0'+af2[j]-'0'+carry;
            int res=sum%10;
            carry=sum/10;
            addf[j]=res+'0';
        }
    }
    //加整数
    l1=strlen(be),l2=strlen(be2);
    if(l1<l2){swap(be,be2),swap(l1,l2);}
   // printf("db be  %s %d\n",be,l1);
    //printf("db be2 %s %d\n",be2,l2);
    int maxl=max(strlen(be),strlen(be2));
    int i;
    for(i=0;i<l1;i++){
        if(i>=l2){
            int sum=be[i]-'0'+carry;
            int res=sum%10;
            carry=sum/10;
            addb[i]=res+'0';
        }else{
            int sum=be[i]-'0'+be2[i]-'0'+carry;
            int res=sum%10;
            carry=sum/10;
            addb[i]=res+'0';
        }
        
    }
    if(carry) addb[i]=carry+'0';
    addb[i+1]='\0';
    //翻转addb
    l1=strlen(addb);
    for(int i=0;i<(l1>>1);i++){
        swap(addb[i],addb[l1-1-i]);
    }
    //去掉addf后0
    l2=strlen(addf);
    for(int i=l2-1;i>=0;i--){
        if(addf[i]!='0') break;
        else addf[i]='\0';
    }
    printf("%s",addb);
    printf(".%s",addf);

    
    return 0;
}