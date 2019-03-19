//单点更新
//区间更新+lazy标记
void build(int p,int l,int r){//维护区间和
    if(l==r){tree[p]=num[l];return ;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tree[p]=tree[p<<1]+tree[p<<1|1];
}
void change(int p,int l,int r,int x,int num){//单点更新
    if(l==r){tree[p]+=num;return ;}
    int mid=(l+r)>>1;
    if(x<=mid) change(p<<1,l,mid,x,num);
    else change(p<<1|1,mid+1,r,x,num);
    tree[p]=tree[p<<1]+tree[p<<1|1];
}
int find(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y) return tree[p];
    int mid=(l+r)>>1;
    if(y<=mid) return find(p<<1,l,mid,x,y);
    if(x>mid return find(p<<1|1,mid+1,r,x,y);
    return find(p<<1,l,mid,x,y)+find(p<<1|1,mid+1,r,x,y);
}
//区间更新
