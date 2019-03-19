#include<bits/stdc++.h>
using namespace std;
int n;
#define maxn 100010
int sum[maxn<<2];//
int lazy[maxn<<2];
void build(int rt,int l,int r){
    if(l==r){sum[rt]=1;return ;}//是sum[rt] 不是[l]
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int rt,int l,int r){
    if(lazy[rt]){
        int mid=(l+r)>>1;
        sum[rt<<1]=(mid-l+1)*lazy[rt];
        sum[rt<<1|1]=(r-mid)*lazy[rt];
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
        lazy[rt]=0;
    }
}
void change(int rt,int l,int r,int x,int y,int t){
    if(x<=l&&r<=y){
        lazy[rt]=t;
        sum[rt]=t*(r-l+1);
        return ;
    }
    pushdown(rt,l,r);
    int mid=(r+l)>>1;
    if(x<=mid) change(rt<<1,l,mid,x,y,t);
    if(y>mid) change(rt<<1|1,mid+1,r,x,y,t);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int rt,int l,int r,int x,int y){
    if(x<=l&&r<=y) return sum[rt];
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(y<=mid) return query(rt<<1,l,mid,x,y);
    if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
    return query(rt<<1,l,mid,x,y)+query(rt<<1|1,mid+1,r,x,y);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        //init
        memset(sum,0,sizeof(sum));
        memset(lazy,0,sizeof(lazy));
        int n,m;
        scanf("%d %d",&n,&m);
        build(1,1,n);
        //printf("db %d %d n %d\n",query(1,1,n,1,n),sum[1],n);
        while(m--){
            int l,r,c;
            scanf("%d %d %d",&l,&r,&c);
            //printf("db ok ?");
            change(1,1,n,l,r,c);

            
        }
        printf("Case %d: The total value of the hook is %d.\n",t,query(1,1,n,1,n));

    }
    return 0;
}