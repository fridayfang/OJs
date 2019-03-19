#include <bits/stdc++.h>
using namespace std;
//author:fridayfang
//date:19 2月 24
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 150000 + 5;
const int maxm = 1e6+5;
//模拟并查集+静态链表
int nxt[maxn],tail[maxn];//nxt[]存储下一个元素
//nxt[i]=0表示链表结束
//tail[]维护边界
int fa[maxn];//并查集
int find(int u){
    return u==fa[u]?u:fa[u]=find(fa[u]);
}
void unio(int u,int v){
    int x=find(u),y=find(v);
    fa[x]=y;
}

int n;
int main(){
    sf(n);
    for(int i=1;i<=n;i++){
        fa[i]=tail[i]=i;
    }
    int r;
    for(int i=1;i<n;i++){
        int u,v;
        sf(u),sf(v);
        int x=find(u),y=find(v);
        fa[x]=y;
        //y代表的链表扩张，合并
        nxt[tail[y]]=x;//y链表尾部静态指针指向x
        tail[y]=tail[x];//y的尾部成为x的尾部
    }
    r=find(1);
    //输出链表
    //for(int r=find(1);r!=0;r=nxt[r]){
        //printf("%d ",r);
    //}
    while(r!=0){
        printf("%d ",r);
        r=nxt[r];
    }

    
    return 0;
}