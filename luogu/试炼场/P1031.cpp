#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=10010;
int a[maxn];

int main(){
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        sum+=a[i];
    }
    int avg=sum/n;
    for(int i=0;i<n;i++){
        a[i]=a[i]-avg;
    }
    int tmp=a[0];
    int mv=0;
    for(int i=1;i<n;i++){
        if(tmp!=0) mv++;
        tmp+=a[i];
    }
    printf("%d\n",mv);
    return 0;

}