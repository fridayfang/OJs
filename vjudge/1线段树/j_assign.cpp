#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//dfs序+线段树
const int maxn=5e4+5;
int head[maxn],l[maxn],r[maxn],used[maxn];
//前向星的存储方式 head[v]是节点v指向的第一条边的编号
//初始化-1
struct edge{
    int to,next;
};//to是边的目标点,next是同起点下一条边的编号
edge egs[maxn];
int cnt;
void adde(int u,int v){
    //u-->v
    egs[++cnt].to=v;
    egs[cnt].next=head[u];
    head[u]=cnt;    
}
int num;
void dfs(int u){
    ++num;
    l[u]=num;
    for(int i=head[u];i!=-1;i=egs[i].next){
        dfs(egs[i].to);
    }
    r[u]=num;

}
//线段树
int lazy[maxn<<3];//节点加倍
//init -1
void pushdown(int rt,int l,int r){
    if(lazy[rt]!=-1){//自己将rt写成r，debug好久
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
int query(int rt,int l,int r,int x){
    //printf("db l %d r %d x %d lazy[rt] %d\n",l,r,x,lazy[rt]);
    if(l==r&&l==x){
        return lazy[rt];
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) return query(rt<<1,l,mid,x);
    else return query(rt<<1|1,mid+1,r,x);

}
int main(){
    //freopn("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        printf("Case #%d:\n",i);
        memset(head,-1,sizeof(head));
        memset(used,0,sizeof(used));
        memset(lazy,-1,sizeof(lazy));
        cnt=0;
        num=0;

        int n,m;
        scanf("%d",&n);
        int u,v;
        for(int j=1;j<n;j++){
            scanf("%d %d",&u,&v);
            adde(v,u);
            used[u]=1;
        }
        for(int i=1;i<=n;i++){//找到根节点dfs序
            if(!used[i]){
                //printf("root %d\n",i);
                dfs(i);
            }
        }
        //db
        /*
        for(int i=1;i<=n;i++){
            printf("i %d l[i] %d r[i] %d\n",i,l[i],r[i]);
        }
        */
        //printf("num %d\n",num);
        //dfs序完成;
        scanf("%d",&m);
        //printf("db ok\n");
        //处理操作
        while(m--){//没加循环 debug好久
        char s[2];
        scanf("%s",s);
        if(s[0]=='C'){
            int x;
            scanf("%d",&x);
            //printf("db query %d %d\n",x,l[x]);
            printf("%d\n",query(1,1,num,l[x]));
            //printf("db query %d %d\n",x,l[x]);
        }
        else if(s[0]=='T'){
            int x,y;
            scanf("%d %d",&x,&y);
            //printf("T %d %d\n",x,y);
            //printf("db task x %d l[x] %d r[x] %d\n",x,l[x],r[x]);
            change(1,1,num,l[x],r[x],y);
            //printf("db change %d %d %d\n",x,l[x],r[x]);
        }
        else{
            printf("error for db\n");
        }
        }
    }
    return 0;
}