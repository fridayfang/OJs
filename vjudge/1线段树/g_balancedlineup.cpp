//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 50010
int num[maxn];
struct info{
    int maxv,minv;
};
info tree[maxn<<2];
void build(int rt,int l,int r){
    if(l==r){
        int v;
        scanf("%d",&v);
        tree[rt].maxv=tree[rt].minv=v;
        return ;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    tree[rt].maxv=max(tree[rt<<1].maxv,tree[rt<<1|1].maxv);
    tree[rt].minv=min(tree[rt<<1].minv,tree[rt<<1|1].minv);
}
void query(int rt,int l,int r, int x,int y,int& maxt,int& mint){
    if(x<=l&&r<=y){
        maxt=max(tree[rt].maxv,maxt);
        mint=min(tree[rt].minv,mint);
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) query(rt<<1,l,mid,x,y,maxt,mint);
    if(y>mid) query(rt<<1|1,mid+1,r,x,y,maxt,mint);

}
int n,q;
int main(){
    scanf("%d %d",&n,&q);
    memset(tree,0,sizeof(tree));
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int maxt=0,mint=0x3f3f3f3f;
        query(1,1,n,x,y,maxt,mint);
        printf("%d\n",maxt-mint);
    }
    return 0;

}