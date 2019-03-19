#include<bits/stdc++.h>
using namespace std;
int mp[5][5]={
    {0,-1,1,1,-1},
    {1,0,-1,1,-1},
    {-1,1,0,-1,1},
    {-1,-1,1,0,1},
    {1,1,-1,-1,0}
    };
int n,na,nb;
int a[210],b[210];
int main(){
    scanf("%d %d %d",&n,&na,&nb);
    int cnta=0,cntb=0;
    for(int i=0;i<na;i++){
        scanf("%d",a+i);
    }
    for(int j=0;j<nb;j++){
        scanf("%d",b+j);
    }
    for(int i=0;i<n;i++){
        int x=a[i%na];
        int y=b[i%nb];
        if(mp[x][y]==1) cnta++;
        if(mp[x][y]==-1) cntb++;
    }
    printf("%d %d\n",cnta,cntb);
    return 0;


}