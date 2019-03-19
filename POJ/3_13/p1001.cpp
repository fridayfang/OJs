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
const int maxn = 200 + 5;
const int maxm = 1e6+5;
char sa[maxn],sb[maxn],sc[maxn];
int num;
char a[maxn],b[maxn],c[maxn];

void mul(char* num1,char* num2){
    //a*b 要求a[0],b[0]是最低位
    int tmp[200];CL(tmp,0);
    int len1=strlen(num1),len2=strlen(num2);
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            tmp[i+j]+=(num1[i]-'0')*(num2[j]-'0');
        }
    }
    int carry=0;
    for(int i=0;i<(len1+len2);i++){
        a[i]=((carry+tmp[i])%10)+'0';
        carry=(carry+tmp[i])/10;
    }
    if(a[len1+len2-1]=='0')a[len1+len2-1]='\0';
    else a[len1+len2]='\0';  

}
void rev(char* str){
    
    for(int i=0,j=strlen(str)-1;i<j;i++,j--){
        swap(str[i],str[j]);
    }
}

int main(){
    while(~scanf("%s %d",sa,&num)){
        CL(a,0),CL(b,0),CL(c,0);
        int lena=strlen(sa),pos=-1;
        int j=0;
        for(int i=0;i<lena;i++){
            if(sa[i]=='.'){pos=i;continue;}
            b[j]=a[j]=sa[i];
            j++;            
        }
        b[j]=a[j]='\0';
        rev(a),rev(b);
        //ok a;
        for(int i=0;i<num-1;i++){
            mul(a,b);//store in b;
            //printf("db %s %s\n",a,b);
        }
        //
        //db(pos);
        if(pos==-1){
            rev(a);
            printf("%s\n",a);
        }
        else{//浮点数
            pos=lena-pos-1;
            int tpos=num*pos;
            //db(tpos);
            int len=strlen(a);
            int t;
            char tmp[maxn];CL(tmp,0);int j=0;
            
            //db(begin);db(tpos);
            bool tag=true;
            for(int t=len;t>=tpos;t--){//加入浮点
                if(t==tpos) a[t]='.';
                else if(a[t-1]=='0'&&tag) a[t]='\0';//消除前导0
                else if(t>=1) {a[t]=a[t-1];tag=false;}
            }
            //消除后导0
            
            a[len+1]='\0';
            int begin=tpos;
            for(int i=0;i<tpos;i++){
                if(a[i]!='0'){begin=i;break;}
            }
            //db(begin);
            if(begin==tpos)begin++;
            for(int i=begin;i<=len;i++){
                tmp[j++]=a[i];
            }
            tmp[j]='\0';
            
            rev(tmp);
            
            printf("%s\n",tmp);

        }
        
    }
    
    return 0;
}