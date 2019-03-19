#include<cstdio>
#include<cstring>
//
#define maxn 100
#define mod 10000
#define baslen 4
struct bint{
    int dig[maxn],len;
    bint(){len=0,dig[0]=0;}
};
//常用函数
void add(bint a,bint b,bint& c){
    int i,carry;
    for(i=carry=0;i<=a.len||i<=b.len||carry;i++){
        if(i<=a.len)
    }
}