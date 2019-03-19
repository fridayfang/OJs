#include<bits/stdc++.h>
using namespace std;
//区间dp上的四边形优化
#define inf 0x3f3f3f3f
#define maxn 210
int sum[maxn],value[maxn];
int dpmax[maxn][maxn],dpmin[maxn][maxn];
int s[maxn][maxn];// min最优决策点
int n;
#define mm0(x) memset(x,0x3f,sizeof(x))
#define mm1(x) memset(x,-1,sizeof(x))
void init(){
    mm1(dpmax);
    mm0(dpmin);
    for(int i=1;i<=2*n;i++){
        sum[i]=sum[i-1]+value[i];
        //printf("db i:%d sum[i] %d\n",i,sum[i]);
    }

}
int minv=inf,maxv=0;
void solve(){
    for(int i=1;i<=2*n;i++){
        dpmax[i][i]=dpmin[i][i]=0;
        s[i][i]=i;
    }
    
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=2*n;i++){
            int j=i+len-1;
            dpmax[i][j]=max(dpmax[i][j-1]+sum[j]-sum[i-1],dpmax[i+1][j]+sum[j]-sum[i-1]);
            //某大佬认为最大值取得必然最后一次合并在左右两端
            //目前自己没有想通和证明
            int idx;
            for(int k=s[i][j-1];k<=s[i+1][j];k++){
                if((dpmin[i][k]+dpmin[k+1][j]+sum[j]-sum[i-1])<dpmin[i][j]){
                    dpmin[i][j]=dpmin[i][k]+dpmin[k+1][j]+sum[j]-sum[i-1];
                    idx=k;
                }
                s[i][j]=idx;               
            }
           // printf("db min: %d k:%d i:%d j: %d\n",dpmin[i][j],s[i][j],i,j);
        }
    }
    for(int i=1;i<=n;i++){
        //printf("db i:%d %d\n",i,dpmin[i][i+n-1]);
        minv=min(dpmin[i][i+n-1],minv);
        maxv=max(dpmax[i][i+n-1],maxv);
    }
    
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",value+i);
        value[i+n]=value[i];
    }
    init();
    solve();
    printf("%d\n%d\n",minv,maxv);
    return 0;
}