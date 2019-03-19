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