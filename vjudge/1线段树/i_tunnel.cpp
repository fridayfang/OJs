#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
int maxv[maxn<<2],minv[maxn<<2];
int n,m;
 void change(int rt,int l,int r,int x,int a,int b){
     //destroy x 加入点x
     if(l==r){
         maxv[rt]=a;
         minv[rt]=b;
         return ;
     }
     int mid=(l+r)>>1;
     if(x<=mid) change(rt<<1,l,mid,x,a,b);
    if(x>mid) change(rt<<1|1,mid+1,r,x,a,b);
    maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
    minv[rt]=min(minv[rt<<1],minv[rt<<1|1]);
 }

void query(int rt,int l,int r,int x,int y,int& maxt,int& mint){
     if(x<=l&&r<=y){
         maxt=max(maxt,maxv[rt]);
         mint=min(mint,minv[rt]);
         return ;
     }
     int mid=(l+r)>>1;
     if(x<=mid) query(rt<<1,l,mid,x,y,maxt,mint);
     if(y>mid) query(rt<<1|1,mid+1,r,x,y,maxt,mint);

 }
stack<int> q;

int main(){
    //cout<<"db\n";
    while(scanf("%d %d",&n,&m)!=EOF){//多组数据
    memset(minv,0x3f,sizeof(minv));
    memset(maxv,0,sizeof(maxv));
    while(!q.empty()){
        q.pop();
    }
    //cout<<"db\n";
    change(1,0,n+1,0,0,0),change(1,0,n+1,n+1,n+1,n+1);
    //printf("minv[1] %d maxv[1] %d\n",minv[1],maxv[1]);
    //cout<<"db0\n";
    for(int i=1;i<=m;i++){
        char str[2];int x;
        scanf("%s",str);
        char c=str[0];
        //printf("db op %c\n",c);
        if(c=='D'){
            scanf("%d",&x);
            change(1,0,n+1,x,x,x);
            //printf("0-4 min %d max %d\n",minv[2],maxv[2]);
            //printf("5-6 min %d max %d\n",minv[6],maxv[6]);
            q.push(x);
        }
        else if(c=='R'){
            int t=q.top();
            q.pop();
            change(1,0,n+1,t,0,0x3f3f3f3f);
        }
        else if(c=='Q'){
            //cout<<"db\n";
            int maxt=0,mint=0x3f3f3f3f;
            scanf("%d",&x);
            //printf("dbQ\n");
            query(1,0,n+1,x,n+1,maxt,mint);
           // printf("Q X %dmint %d\n",x,mint);
            int ansmin=mint;
            maxt=0,mint=0x3f3f3f3f;
            query(1,0,n+1,0,x,maxt,mint);
            //printf("Q x %d maxt %d\n",x,maxt);
            int ansmax=maxt;
            int ans =(ansmin-ansmax-1)<0?0:ansmin-ansmax-1;
            printf("%d\n",ans);
        }
    }
    }
    return 0;

}
