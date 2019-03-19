#include<cstdio>
#include<cstring>
#define maxn 1000
//¸ß¾«¶È
struct bnum{
    int a[maxn],len;
    bnum(){len=0,a[0]=0;}
};
void input(bnum &b){
    int i,j=0;
    char str[maxn+2];
    scanf("%s",str);
    int slen=strlen(str);
    for(i=slen-1;i>=0;i--){
        b.a[j++]=str[i]-'0';
    }
    b.len=slen;
}
void add(bnum b1,bnum b2,bnum& c){
    int i;
    int car=0;
    for(i=0;i<b1.len||i<b2.len||car;i++){
        car+=b1.a[i];
        car+=b2.a[i];
        c.a[i]=car%10;
        car=car/10;
       // printf("db:%d %d\n",i,c.a[i]);

    }
    if(c.a[i]>0) c.len=i+1;
    else c.len=i;
}
void output(bnum c){
    if(c.len==0){
        printf("0\n");
        return ;
    }
    for(int j=c.len-1;j>=0;j--){
        printf("%d",c.a[j]);
    }
    printf("\n");
}
int main(){
    bnum b1,b2,c;
    memset(b1.a,0,sizeof(b1.a));
    memset(b2.a,0,sizeof(b2.a));
    memset(c.a,0,sizeof(c.a));
    input(b1);input(b2);
    //db
    //output(b1);
    //output(b2);
    add(b1,b2,c);
    output(c);
    return 0;
}
