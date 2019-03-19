#include<bits/stdc++.h>
using namespace std;
int m,n,k,l,d;
struct p{
    int num;
    int pos;
};
bool cmp0(p a,p b){
    return a.num>b.num;
}
bool cmp(p a,p b){
    return a.pos<b.pos;
}
const int maxn=10010;
p px[maxn];
p py[maxn];
int main(){
    scanf("%d %d %d %d %d",&m,&n,&k,&l,&d);
    //init
    //printf("m%d n%d k%d l%d\n",m,n,k,l);
    for(int i=0;i<=m;i++){
        px[i].num=0;px[i].pos=i;
    }
    for(int j=0;j<=n;j++){
        py[j].num=0;py[j].pos=j;
    }

    for(int i=1;i<=d;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int div;
        if(x1==x2){//1写成2 bug
            div=min(y1,y2);//多写了·一个= bug
            py[div].num++;
        }
        else{
            div=min(x1,x2);;
            px[div].num++;
        } 
    }
    sort(px+1,px+m,cmp0);
    sort(py+1,py+n,cmp0);
    /*
    for(int i=0;i<m;i++){
        printf("num %d pos %d\n",px[i].num,px[i].pos);
    }
    */
    
    sort(px+1,px+k+1,cmp);
    sort(py+1,py+l+1,cmp);
    //printf("m%d n%d k%d l%d\n",m,n,k,l);
    for(int i=1;i<=k;i++){
        if(i==1) printf("%d",px[i].pos);
        else printf(" %d",px[i].pos);;
    }
    printf("\n");
    for(int j=1;j<=l;j++){
        if(j==1) printf("%d",py[j].pos);
        else printf(" %d",py[j].pos);
    }
    return 0;
    
}