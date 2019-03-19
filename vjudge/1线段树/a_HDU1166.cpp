#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
#define mm(x) memset(x,0,sizeof(x))
#define maxn 50000
int Sum[maxn<<2];
int num[maxn+10];
int cases,numbers;
char cmd[10];//command
void build(int x,int l,int r){
    if(l==r){Sum[x]=num[l];return ;}
    int mid=l+((r-l)>>1);
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    Sum[x]=Sum[x<<1]+Sum[x<<1|1];
}
void add(int a,int b,int l,int r,int x){//num[a]+=b,Sum[x] x=1
    if(l==r&&a==l){Sum[x]+=b;return ;}
    int mid=l+((r-l)>>1);
    if(a<=mid) add(a,b,l,mid,x<<1);//这里条件判断只和a有关,num[a]
    else add(a,b,mid+1,r,x<<1|1);
    Sum[x]=Sum[x<<1]+Sum[x<<1|1];
}
int query(int a,int b,int l,int r,int x){//range[a,b] query from x
    if(a<=l&&r<=b) return Sum[x];
    int mid=l+((r-l)>>1);
    if(b<=mid) return query(a,b,l,mid,x<<1);//这里和a,b都有关
    if(a>mid) return query(a,b,mid+1,r,x<<1|1);
    return query(a,b,l,mid,x<<1)+query(a,b,mid+1,r,x<<1|1);
}
int main(){
    scanf("%d",&cases);
    int i=1;
    int a,b;
    while(i<=cases){
        //
        mm(Sum);
        mm(num);
        printf("Case %d:\n",i);
        scanf("%d",&numbers);
        for(int i=1;i<=numbers;i++){
            scanf("%d",&num[i]);
        }
        build(1,1,numbers);
        while(scanf("%s",cmd)&&strcmp(cmd,"End")!=0){
           // scanf("%d %d",&a,&b);
            if(strcmp(cmd,"Add")==0){
                scanf("%d %d",&a,&b);
                add(a,b,1,numbers,1);
            }
            else if(strcmp(cmd,"Sub")==0){
                   // printf("debug Sub\n");
                scanf("%d %d",&a,&b);
                add(a,-b,1,numbers,1);
            }
            else if(strcmp(cmd,"Query")==0){
                //printf("debug query\n");
                scanf("%d %d",&a,&b);
                printf("%d\n",query(a,b,1,numbers,1));
            }
            else break;
        }

        i++;
    }
    //system("pause");
    return 0;
}
/*
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End
*/
