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

char smp[4][4],tmp[4][4];
int curx,cury;//当前位置
int mv[4][2]={{-1,0},{1,0},{0,1},{1,0}};
void mv(){
    for(int i=0;i<4;i++){
        //'l' 'r' 'd' 'u'
        int newx=curx+mv[i][0],newy=cury+mv[i][1];
        swap(tmp[curx][cur[y],tmp[newx][newy]);
        int 
        

    }
}

int main(){
    
    return 0;
}