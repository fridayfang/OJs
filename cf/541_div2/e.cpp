#include <bits/stdc++.h>
using namespace std;
//author:fridayfang
//date:19 2? 24
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e5 + 5;
const int maxm = 1e6+5;
//???
int sc[26];//sc[i][j] ????'a'+j??
char str[maxn];

void update(char* s,int len){
    char c0=s[0],char c1=s[len-1];
    if(c0!=c1){
        
    }
}

void solve(){
    //init
    scanf("%s",str);
    char c=str[0],sc[c-'a']++;
    int cnt=1;
    for(int i=1;i<strlen(str);i++){
        if(str[i]==str[i-1]){
            cnt++;
            if(cnt>sc[c-'a']) sc[c-'a']=cnt;
        }
        else{
            c=str[i];
            cnt=1;
            if(cnt>sc[c-'a']) sc[c-'a']=cnt;
        }
    }


}



int main(){
    
    return 0;
}