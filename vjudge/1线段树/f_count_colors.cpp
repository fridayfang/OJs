#include<bits/stdc++.h>
using namespace std;
#define maxn 8010
#define mm0(x) memset(x,0,sizeof(x))
#define mm1(x) memset(x,-1,sizeof(x))
int num[maxn],lazy[maxn<<2];
void pushdown(int rt,int l,int r){
    if(lazy[rt]!=-1){
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
        lazy[rt]=-1;
    }
}
void change(int rt,int l,int r,int x,int y,int c){
    if(x<=l&&r<=y){
        lazy[rt]=c;
        return ;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) change(rt<<1,l,mid,x,y,c);
    if(y>mid) change(rt<<1|1,mid+1,r,x,y,c);

}
void query(int rt,int l,int r,int x,int y){
    //将所有lazy下放到低端
    //pushdown(rt,l,r);
    if(l==r){num[l]=lazy[rt];return ;}
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    query(rt<<1,l,mid,x,y);
    query(rt<<1|1,mid+1,r,x,y);
}
int has[maxn];
void count(){
    int tmp=-1,cnt=0;
    for(int i=1;i<=8000;i++){
        if(num[i]!=tmp){
            cnt++;
            if(num[i]!=-1) has[num[i]]++;
            tmp=num[i];
        }
    }
    for(int i=0;i<=8000;i++){
        if(has[i]){
            printf("%d %d\n",i,has[i]);
        }
    }

}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        //init
        mm1(num);
        mm1(lazy);
        mm0(has);
        int x,y,c;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&x,&y,&c);
            change(1,1,8000,x+1,y,c);
        }
        query(1,1,8000,1,8000);
        count();
        printf("\n");
    }
    return 0;
}