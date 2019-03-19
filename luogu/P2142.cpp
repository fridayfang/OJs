//高精度减法
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 10000
struct Bnum{
    int bit[maxn+10],len;
    Bnum(){memset(bit,0,sizeof(bit)),len=0;}
};
Bnum c1,c2,c3;
//正整数的类
void input(Bnum& bnum){
    char str[maxn];
    scanf("%s",str);
    int slen=strlen(str);
    int j=0;
    for(int i=slen-1;i>=0;i--){
        bnum.bit[j++]=str[i]-'0';
    }
    bnum.len=slen;
}
void output(Bnum bnum){
    if(bnum.len==0){
        printf("0\n");
        return ;
    }
    for(int i=bnum.len-1;i>=0;i--){
        printf("%d",bnum.bit[i]);
    }
    printf("\n");
}
void add(Bnum a,Bnum b,Bnum& c){
    int carry=0;
    int i;
    for(i=0;i<a.len||i<b.len;i++){
        c.bit[i]=(a.bit[i]+b.bit[i]+carry)%10;
        carry=(a.bit[i]+b.bit[i]+carry)/10;
    }
    if(carry==0) c.len=i;
    else{
        c.bit[i]=carry;
        c.len=i+1;
    }
}
void helper_sub(Bnum a,Bnum b,Bnum& c){
    //require(a>b)
    for(int i=0;i<a.len||i<b.len;i++){
        if(a.bit[i]-b.bit[i]>=0){
            c.bit[i]=a.bit[i]-b.bit[i];
        }
        else{
            c.bit[i]=(a.bit[i]-b.bit[i]+10);
            a.bit[i+1]--;
        }
    }
    for(int i=a.len-1;i>=0;i--){
        if(c.bit[i]!=0){
            c.len=i+1;break;
        }
    }
}
void sub(Bnum a,Bnum b,Bnum& c){
    bool flag=true;//result is positive
    if(a.len<b.len) flag=false;
    if(a.len==b.len){
        for(int i=a.len-1;i>=0;i--){
            if(a.bit[i]<b.bit[i]) flag=false;
        }
    }
    if(flag==true){
        helper_sub(a,b,c);
        output(c);
    }
    else{
        helper_sub(b,a,c);
        printf("-");
        output(c);
    }
}
int main(){
    //printf("db hello\n");
    input(c1);input(c2);
    sub(c1,c2,c3);
    //printf("db:nothing\n");
    //output(c3);
    return 0;

}
