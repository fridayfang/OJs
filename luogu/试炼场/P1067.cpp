#include<bits/stdc++.h>
using namespace std;
void output(int n,int k,bool first){//nx^k
    bool zero=(n==0);
    bool zero1=(k==0);
    if(zero) return ;
    if(first){
        if(n>0) ;
        else printf("-");
        if(abs(n)!=1) printf("%d",abs(n));
        printf("x^%d",k);
    }
    else{
        //add "+" "-"
        if(n>0) printf("+");
        else printf("-");
        if(k==0) printf("%d",abs(n));
        else if(abs(n)>1&&k!=1) printf("%dx^%d",abs(n),k);
        else if(abs(n)>1&&k==1) printf("%dx",abs(n));
        else if(abs(n)==1&&k!=1) printf("x^%d",k);
        else if(abs(n)==1&&k==1) printf("x");


    }
    
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=t;i>=0;i--){
        int a;
        scanf("%d",&a);
        output(a,i,i==t);
    }
    return 0;
}