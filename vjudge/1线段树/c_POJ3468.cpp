#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 100000
#define mm(x) memset(x,0,sizeof(x))
long long Sum[maxn<<2];
int lazy[maxn<<2];
int nums[maxn+10];
int size,ops;
char option;
//The sums may exceed the range of 32-bit integers.
void build(int x,int l,int r){
    if(l==r){Sum[x]=nums[l];return;}
    int mid=l+((r-l)>>1);
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    Sum[x]=Sum[x<<1]+Sum[x<<1|1];
}
void pushDown(int x,int len){//len是lazy[p] 管辖的长度
    if(lazy[x]){
        Sum[x<<1]+=(long long)lazy[x]*(len-((len)>>1));
        Sum[x<<1|1]+=(long long)lazy[x]*(len>>1);
        lazy[x<<1]+=lazy[x];//+=不是=
        lazy[x<<1|1]+=lazy[x];
        lazy[x]=0;
    }
}
void add(int x,int a,int b,int c,int l,int r){
    if(a<=l&&r<=b){
        lazy[x]+=c;
        Sum[x]+=(long long)c*(r-l+1);
        return ;
    }
    pushDown(x,r-l+1);
    int mid=l+((r-l)>>1);
    if(a<=mid) add(x<<1,a,b,c,l,mid);
    if(b>mid) add(x<<1|1,a,b,c,mid+1,r);
    Sum[x]=Sum[x<<1]+Sum[x<<1|1];
}
long long query(int x,int a,int b,int l,int r){
    if(a<=l&&r<=b){return Sum[x];}
    pushDown(x,r-l+1);
    int mid=l+((r-l)>>1);
    if(b<=mid) return query(x<<1,a,b,l,mid);
    if(a>mid) return query(x<<1|1,a,b,mid+1,r);
    return query(x<<1,a,b,l,mid)+query(x<<1|1,a,b,mid+1,r);
}
int main(){
    while(~scanf("%d %d",&size,&ops)){
        mm(Sum);
        mm(lazy);
        mm(nums);
        for(int i=1;i<=size;i++){
            scanf("%d",&nums[i]);
        }
        build(1,1,size);
        int a,b;
        int c;
        char str[3];
        for(int j=1;j<=ops;j++){
            scanf("%s",str);
            //printf("%c\n",c);
            if((str[0]=='Q')){
                //printf("debug question\n");
                scanf("%d %d",&a,&b);
                //printf("%d %d\n",a,b);
                printf("%lld\n",query(1,a,b,1,size));
            }
            else if(str[0]=='C'){
                scanf("%d %d %d",&a,&b,&c);
                add(1,a,b,c,1,size);
            }

        }

    }
    return 0;
}
/*
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
*/
