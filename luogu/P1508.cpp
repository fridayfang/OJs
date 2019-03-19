#include<bits/stdc++.h>
using namespace std;
#define maxn 210
int m,n;
int mp[maxn][maxn];
int max3(int a,int b,int c){
    if(a>b&&a>c) return a;
    else return b>c?b:c;

}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            mp[i][j]=max3(mp[i-1][j],mp[i-1][j-1],mp[i-1][j+1])+mp[i][j];

        }
    }
    int maxe=-2e8;
    for(int j=n/2;j<=n/2+2;j++){
        maxe=max(mp[m][j],maxe);
    }
    printf("%d\n",maxe);
    return 0;
}