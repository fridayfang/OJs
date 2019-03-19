#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll unsigned long long
ll sum[maxn<<2];
int lazy[maxn<<2];
void build(int rt,int l,int r){
    if(l==r){
        scanf("%lld",&sum[rt]);//什么类型就用什么类型的输入输出，否则会WA
        return ;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void change(int rt,int l,int r,int x,int y){
    //单点更新不用lazy标记
   // printf("db rt:%d l %d r %d x %d y %d sum[rt] %d\n",rt,l,r,x,y,sum[rt]);
    if(sum[rt]<=(r-l+1)){
        return ;
    }
    if(l==r&&l>=x&&l<=y){
        sum[rt]=(ll)sqrt(sum[rt]);
        return ;
    }    
    int mid=(l+r)>>1;
    if(x<=mid) change(rt<<1,l,mid,x,y);
    if(y>mid) change(rt<<1|1,mid+1,r,x,y);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
ll query(int rt,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return sum[rt];
    }
    int mid=(l+r)>>1;
    if(y<=mid) return query(rt<<1,l,mid,x,y);
    if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
    return query(rt<<1,l,mid,x,y)+query(rt<<1|1,mid+1,r,x,y);
}
int main(){
    int n,m;
    int cnt=1;
    while(scanf("%d",&n)!=EOF){
        printf("Case #%d:\n",cnt);
        cnt++;
    memset(sum,0,sizeof(sum));
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int x,y,c;
        scanf("%d %d %d",&c,&x,&y);
        int tmp0=max(x,y),tmp1=min(x,y);
        x=tmp1,y=tmp0;

        if(c==0) change(1,1,n,x,y);
        else printf("%lld\n",query(1,1,n,x,y));

    }
    printf("\n");
    }
    return 0;

}

