#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 2月 27
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int n;
int a[500];
int used[500];//是否在被使用
int slen,snum;//standard len; standard num of sticks
int dfs(int len,int stick,int pos){//len当前组成的长度,stick正在拼凑第几根棍子,pos:枚举的起点
    if(stick==snum) return 1;
    for(int j=pos;j<n;j++){
        //尝试每根棍子
        if(used[j]) continue;//用过了不能再用
        if(len+a[j]==slen){//恰好组成一根棍子
            used[j]=1;//被占用
            if(dfs(0,stick+1,0)){//找下一stick要从头开始
                return 1;
            }
            //如果没找到下一个棍子,应该回溯
            used[j]=0;
        }
        else if(len+a[j]<slen){
            used[j]=1;//尝试使用
            if(dfs(len+a[j],stick,pos+1)){//要向下枚举凑成棍子
                return 1;
            }
            //回溯
            used[j]=0;
        }
        if(len==0) break;//表示没有选到合适的
        //a[j]不行，那么与a[j]相等的都不行
        while(a[j]==a[j+1]) j++;
    }
    return 0;

}
bool cmp(int a,int b){return a>b;}

int main(){
    while(sf(n)&&n!=0){
        CL(used,0);
        int sum=0;fr0(i,n){sf(a[i]);sum+=a[i];}
    
        sort(a,a+n,cmp);
        //fr0(i,n){printf("db%d ",a[i]);}
        int maxseg=64>(int)(sum/a[0])?(int)(sum/a[0]):64;
        for(int seg=maxseg;seg>=1;seg--){
            if(sum%seg!=0) continue;
            slen=sum/seg,snum=seg;
            if(dfs(0,1,0)){
                printf("%d\n",slen);
                break;
            }
        }
    }
    

    
    return 0;
}