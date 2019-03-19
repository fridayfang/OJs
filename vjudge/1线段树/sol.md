# vj线段树专题题解
## 单点更新模板
```cpp
void build(int x,int l,int r){//sum[x]控制l-r区域
    if(l==r){Sum[x]=num[l];return ;}
    int mid=l+((r-l)>>1);
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    Sum[x]=Sum[x<<1]+Sum[x<<1|1];
}
void add(int a,int b,int l,int r,int x){//num[a]+=b,Sum[x] x=1 单点a增加b
    if(l==r&&a==l){Sum[x]+=b;return ;}
    int mid=l+((r-l)>>1);
    if(a<=mid) add(a,b,l,mid,x<<1);//这里条件判断只和a有关,num[a]
    else add(a,b,mid+1,r,x<<1|1);
    Sum[x]=Sum[x<<1]+Sum[x<<1|1];
}
int query(int a,int b,int l,int r,int x){//range[a,b] query from x 查询区域a-b之间信息
    if(a<=l&&r<=b) return Sum[x];
    int mid=l+((r-l)>>1);
    if(b<=mid) return query(a,b,l,mid,x<<1);//这里和a,b都有关
    if(a>mid) return query(a,b,mid+1,r,x<<1|1);
    return query(a,b,l,mid,x<<1)+query(a,b,mid+1,r,x<<1|1);
}

```
## 区间更新模板
```cpp
void build(int x,int l,int r){
    if(l==r){Sum[x]=nums[l];return;}
    int mid=l+((r-l)>>1);
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    Sum[x]=Sum[x<<1]+Sum[x<<1|1];
}
void pushDown(int x,int len){//len是lazy[p] 管辖的长度
    if(lazy[x]){//先下放到下面，然后将lazy[]置0
        Sum[x<<1]+=(long long)lazy[x]*(len-((len)>>1));
        Sum[x<<1|1]+=(long long)lazy[x]*(len>>1);
        lazy[x<<1]+=lazy[x];//+=不是=
        lazy[x<<1|1]+=lazy[x];
        lazy[x]=0;
    }
}
void add(int x,int a,int b,int c,int l,int r){
    if(a<=l&&r<=b){//如果要更新的区间覆盖了当控制的区间，设置lazy标记后结束
        lazy[x]+=c;
        Sum[x]+=(long long)c*(r-l+1);
        return ;
    }
    pushDown(x,r-l+1);//否则检查是否由lazy标记,pushDown
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
```
## 题解
### a_HDU1166 A - 敌兵布阵
简单的单点更新，动态查询(询问次数很多)，是模板题;
每个营地代表一个点，每次查询或更新
### 代码(略)
### B - I Hate It HDU - 1754
### 代码略
### C - A Simple Problem with Integers 
区间更新的模板题(lazy标记)
### 代码略
### D - Mayor's posters
令人难受的非动态查询的线段树题目
### 题解
- 每次贴不同宽度的海报，问经过最后能看见几张海报
- 离散化+线段树,离散化时注意>1意味着并非紧邻，蓑衣离散化后也应该保持非紧邻
- unique,sort,lower_bound函数的参数都是.end(),可以理解为最后一个元素的下一位

### 附上代码
```cpp
//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define maxn 20010
struct poster{
    int lb,rb;//left bound
};
poster ps[10010];
int a[maxn<<1],b[maxn<<1];
int col[maxn<<3];//维护区间海报颜色种数
bool has[maxn];//维护区间某种颜色知否被标记

int n,ans;
void pushdown(int rt){
    if(col[rt]){
        col[rt<<1]=col[rt<<1|1]=col[rt];
        col[rt]=0;
    }
}
void update(int rt,int l,int r,int x,int y,int co){
    //在区间x-y贴颜色co的海报(区间更新)
    if(x<=l&&r<=y){
        col[rt]=co;
        return ;
    }
    if(l==r) return ;
    pushdown(rt);
    int mid=(l+r)>>1;
    if(x<=mid) update(rt<<1,l,mid,x,y,co);
    if(y>mid) update(rt<<1|1,mid+1,r,x,y,co);
    //因为不是动态询问，所以不用子节点更新父节点
    //而动态询问实际上信息很难维护，这也应该是出题人考虑到了

}
void query(int rt,int l,int r){
    if(col[rt]){
        if(!has[col[rt]]) ans++;//该颜色尚未计数
        has[col[rt]]=true;
        return ;
    }
    if(l==r) return ;
    int mid=(l+r)>>1;
    query(rt<<1,l,mid);
    query(rt<<1|1,mid+1,r);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        //init
        memset(col,0,sizeof(col));
        memset(has,0,sizeof(has));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ans=0;
        int cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&ps[i].lb,&ps[i].rb);
            a[cnt++]=ps[i].lb;//a[]用于排序和离散化
            a[cnt++]=ps[i].rb;

        }
        //cout<<"db ok \n"<<endl;
        sort(a,a+cnt);
        cnt=unique(a,a+cnt)-a;
        int cnt2=1;
        b[cnt2]=a[0];
        for(int i=1;i<cnt;i++){
            //printf("%d %d\n",i,a[i]);
            if(a[i]-a[i-1]>1){
                //加点
                b[++cnt2]=a[i]-1;
                b[++cnt2]=a[i];
            }
            else{
                b[++cnt2]=a[i];
            }
        }
        //cout<<"db ok 2\n"<<cnt2<<"cnt2\n"<<endl;
        //离散化完成 b[]用于建立线段树
        //距离>2的点实际并不紧邻
        for(int i=1;i<=n;i++){
            int x=lower_bound(b+1,b+cnt2+1,ps[i].lb)-b;
            int y=lower_bound(b+1,b+cnt2+1,ps[i].rb)-b;
           // cout<<x<<" "<<y<<" "<<endl;
           // cout<<"db ok 4\n"<<endl;
            update(1,1,cnt2,x,y,i);
        }
        //cout<<"db ok 3\n"<<endl;
        query(1,1,cnt2);
        printf("%d\n",ans);


    }
    return 0;
}
```





