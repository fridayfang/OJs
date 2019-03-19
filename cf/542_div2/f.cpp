#include<bits/stdc++.h>
using namespace std;
#define fr0(i, m) for(int i=0;i<m;i++)

//构造题
int k;
int ans[2004];
int a[2000];
int main(){
    ans[2]=-1;
    scanf("%d",&k);
    //寻找n
    int n;
    for(n=2;n<=2000;n++){
        if((1002000+k)<=(n-1)*1000000) break;
    }
    int x=(n+k)/(n-2);
   //printf("db %d %d\n",x,n);
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        if(i==0) a[0]=-1;
        else if(i==n-1){
            a[i]=n+k-x*(n-2);
            //printf(" %d",n+k-x*(n-2));
        }
        else{
            a[i]=x;
        }
    }

    fr0(i,n){
        printf("%d ",a[i]);
    }
    return 0;
}