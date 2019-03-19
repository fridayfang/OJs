#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define mm(x) memset(x,0,sizeof(x))
#define maxn 200000
int num[maxn+10];
int mx[maxn<<2];
int sizes,ops;
char c;
void build(int x,int l,int r){
    if(l==r){mx[x]=num[l];return ;}
    int mid=l+((r-l)>>1);
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
void update(int a,int b,int l,int r,int x){//num[a]
    if(l==r&&a==l){mx[x]=b;return ;}
    int mid=l+((r-l)>>1);
    if(a<=mid) update(a,b,l,mid,x<<1);
    else update(a,b,mid+1,r,x<<1|1);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
int query(int a,int b,int l,int r,int x){
    if(a<=l&&r<=b){return mx[x];}
    int mid=l+((r-l)>>1);
    if(b<=mid) return query(a,b,l,mid,x<<1);
    if(a>mid) return query(a,b,mid+1,r,x<<1|1);
    return max(query(a,b,l,mid,x<<1),query(a,b,mid+1,r,x<<1|1));
}
int main(){
    int a,b;
    while(scanf("%d %d",&sizes,&ops)!=EOF){;
    mm(num);
    mm(mx);
    for(int i=1;i<=sizes;i++){
        scanf("%d",&num[i]);
    }
    build(1,1,sizes);
    getchar();
    for(int j=1;j<=ops;j++){
        //fflush(stdin);
        scanf("%c",&c);
        if(c=='Q'){
            scanf("%d %d",&a,&b);
            getchar();
            printf("%d\n",query(a,b,1,sizes,1));
        }
        else{
            scanf("%d %d",&a,&b);
            getchar();
            update(a,b,1,sizes,1);
        }
    }
    }
    return 0;
}
/*
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5
*/
