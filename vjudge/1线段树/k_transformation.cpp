#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
#define ll long long
#define mm0(x) memset(x,0,sizeof(x))
int n,m;
const int mod=10007;
#define ls rt<<1
#define rs rt<<1|1
ll sum1[maxn<<3],sum2[maxn<<3],sum3[maxn<<3];
struct lay{
    int op,c;
};
//这种解法无法写出成段更新
//成段更新的关键在于 如果当前段已有lazy
//这里的办法是lazy标记应该有3钟状态
//错误代码
lay lazy[maxn<<3];
void pushdown(int rt,int l,int r){
    if(lazy[rt].op!=-1){
        int op=lazy[rt].op;
        int c=lazy[rt].c;
        int mid=(l+r)>>1;
        int llen=(mid-l+1);
        int rlen=(r-mid);
        //printf("db pushdown rt %d op %d c %d\n",rt,op,c);
        if(op==2){
            sum1[rt<<1]=(sum1[rt<<1]*c);//%mod;
            sum1[rt<<1|1]=(sum1[rt<<1|1]*c);//%mod;
            sum2[rt<<1]=(sum2[rt<<1]*c*c);///%mod;
            sum2[rt<<1|1]=(sum2[rt<<1|1]*c*c);//%mod;
            sum3[rt<<1]=(sum3[rt<<1]*c*c*c);///%mod;
            sum3[rt<<1|1]=(sum3[rt<<1|1]*c*c*c);///%mod;
            lazy[rt<<1].c=lazy[rt<<1|1].c=c;

        }
        else if(op==1){
            sum3[ls]=(sum3[ls]+3*c*sum2[ls]+3*c*c*sum1[ls]+c*c*c*llen);//%mod;
            sum3[rs]=(sum3[rs]+3*c*sum2[rs]+3*c*c*sum1[rs]+c*c*c*rlen);//%mod;
            sum2[ls]=(sum2[ls]+2*c*sum1[ls]+c*c*llen);//%mod;
            sum2[rs]=(sum2[rs]+2*c*sum1[rs]+c*c*rlen);//%mod;
            sum1[ls]=(sum1[ls]+c*llen);//%mod;
            sum1[rs]=(sum1[rs]+c*rlen);//%mod; 
            lazy[rt<<1].c=lazy[rt<<1|1].c=c;      
            

        }
        else if(op==3){
            sum1[ls]=(c*llen);//%mod;
            sum1[rs]=(c*rlen);///%mod;
            sum2[ls]=(c*c*llen);//%mod;
            sum2[rs]=(c*c*rlen);//%mod;
            sum3[ls]=(c*c*c*llen);//%mod;
            sum3[rs]=(c*c*c*rlen);//%mod;    
            lazy[rt<<1].c=lazy[rt<<1|1].c=c;
        }
        lazy[rt<<1].op=lazy[rt<<1|1].op=op;
        lazy[rt].op=-1;
        sum1[rt]=sum1[rt<<1]+sum1[rt<<1|1];
        sum2[rt]=sum2[rt<<1]+sum2[rt<<1|1];
        sum3[rt]=sum3[rt<<1]+sum3[rt<<1|1];
    }
}
void change(int rt,int l,int r,int x,int y,int c,int op){
    pushdown(rt,l,r);
    if(x<=l&&r<=y){//成段更新
        int len=r-l+1;
       //printf("db 成段更新 rt %d len %d op %d c %d\n",rt,len,op,c);
       
        if(op==2){
            sum1[rt]=sum1[rt]*c;
            sum2[rt]=sum2[rt]*c*c;
            sum3[rt]=sum3[rt]*c*c*c;
            //printf("db op=2 rt %d %lld %lld %lld\n",rt,sum1[rt],sum2[rt],sum3[rt]);
            //if(lazy[rt].op==op) lazy[rt].c*=c;
        }
        else if(op==1){
            sum3[rt]=sum3[rt]+3*c*sum2[rt]+3*c*c*sum1[rt]+c*c*c*len;
            sum2[rt]=sum2[rt]+2*c*sum1[rt]+c*c*len;//+
            sum1[rt]=sum1[rt]+c*len;
            //printf("db op=1 rt %d %lld %lld %lld\n",rt,sum1[rt],sum2[rt],sum3[rt]);
            //if(lazy[rt].op==op) lazy[rt].c+=c;
        }
        else if(op==3){
            sum1[rt]=c*len;sum2[rt]=c*c*len;sum3[rt]=c*c*c*len;
          // printf("db op=3 rt %d %lld %lld %lld\n",rt,sum1[rt],sum2[rt],sum3[rt]);
           //lazy[rt].c=c;
        }
        lazy[rt].op=op;
        lazy[rt].c=c;

        
        return ;


    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) change(rt<<1,l,mid,x,y,c,op);
    if(y>mid) change(rt<<1|1,mid+1,r,x,y,c,op);
    sum1[rt]=sum1[rt<<1]+sum1[rt<<1|1];
        sum2[rt]=sum2[rt<<1]+sum2[rt<<1|1];
        sum3[rt]=sum3[rt<<1]+sum3[rt<<1|1];

}
ll query(int rt,int l,int r,int x,int y,int p){
    if(x<=l&&r<=y){
        //printf("db query rt %d l r %d %d p%d %lld\n",rt,l,r,p,sum3[rt]);
        if(p==1) return sum1[rt];
        else if(p==2) return sum2[rt];
        else return sum3[rt];
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(y<=mid) return query(rt<<1,l,mid,x,y,p);
    if(x>mid) return query(rt<<1|1,mid+1,r,x,y,p);
    return query(rt<<1,l,mid,x,y,p)+query(rt<<1|1,mid+1,r,x,y,p);//带码写准确
}



int main(){
    while(scanf("%d %d",&n,&m)&&(n!=0)){
        int x,y,c,op;
        memset(lazy,-1,sizeof(lazy));
        mm0(sum1);
        mm0(sum2);
        mm0(sum3);
        for(int i=1;i<=m;i++){
            scanf("%d %d %d %d",&op,&x,&y,&c);
        
        if(op!=4){
            change(1,1,n,x,y,c,op);
            //printf("db sum*[1] %d %d %d\n",sum1[1],sum2[1],sum3[1]);
            /*
            for(int i=1;i<=16;i=i*2){
                printf("db i %d %lld \n",i,sum1[i]);
            }
            printf("db over\n\n\n");
            */
            
        }
        else{
            printf("%lld\n",query(1,1,n,x,y,c)%mod);
        }
        }

    }
    return 0;
}