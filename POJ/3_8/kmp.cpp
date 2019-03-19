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
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
//strlen(p) 返回值是无符号数
//无符号数和有符号数比较会将有符号转变为无符号
int nxt[100];//模式串next数组
char p[100];
char text[1000];
void get_next(){
    nxt[0]=-1;
    int i=0,j=-1;
    while(i<(int)strlen(p)){
        if(j==-1||p[j]==p[i]){
            j++;i++;
            nxt[i]=(p[i]==p[j])?nxt[j]:j;//这是一个优化
            //nxt[i]=j;//应该也不会卡
        }
        else j=nxt[j];
    }

}
int kmp(){
    int i=0;
    int j=0;
    db(strlen(p)),db(strlen(text));
    int len=strlen(p);
    printf("%x\n",-1);
    //while((j<len)&&(i<8)){
    while((j < (int)strlen(p))&&(i<8)){
        //db(i),db(j);
        if(j==-1||p[j]==text[i]){
            i++;j++;
        }
        else j=nxt[j];
        //db(i),db(j);
    }
    db(i),db(j);
    if(j==strlen(p)) return i-j;
    else return -1;

}

int main(){
    scanf("%s %s",text,p);

    get_next();
    for(int i=0;i<strlen(p);i++)printf("%d ",nxt[i]);
    int pos=kmp();
    db(pos);
    
    return 0;
}