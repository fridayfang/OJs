#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define name2str(name) (#name)
#define db(x) cout<<#x"=["<<(x)<<"]"<<endl
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define rng(a) a.begin(),a.end()
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
//author:fridayfang
//date:19 3月 11
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;

//终于明白了这道题的做法，考虑相邻两行
/*
k:   1   1   0   0
k+1: 0   1   0   1
    (1) (2) (3) (4)
横着放定义为11,竖着放定义为0
                         1
考虑k和k+1行的状态s_k,s_{k+1},那么
条件1: s_k|s_{k+1}==11111(全1)才可能合法
条件2；s_k&s_{k+1}必须每个连续段有连续偶数个1，因为s_k&s_{k+1}某位出现1，意味上下都是1，那么下面必须都横铺，所以需要偶数个1
条件2的说明 11011合法 1110111不合法 1011不合法

*/
//先算术运算，后移位运算，最后位运算;位运算和移位运算一定要加括号
int h,w;
ll dp[1<<13][13];//dp[state][j] row_j为状态state的情况
//dp[state][j]=sum(dp[state'][j-1])  state和state'需满足条件1和2
bool check(int s){
    //检查某个状态是否有连续偶数个1
    int ans=0;
    while(s>0){
        if(s&1){ans++;}
        else{//某位出现0，ans统计了连续段1情况
            if(ans&1)return false;
            ans=0;
        }
        s>>=1;//
    }
    if(ans&1)return false;
    return true;
}
bool ok(int s1,int s2){//检验两个状态是否合法(满足上述两个条件)
    if((s1|s2)==((1<<w)-1)&&(check(s1&s2)))return true;
    return false;
}

int main(){
    while(scanf("%d %d",&h,&w)&&h){
        //用w位表示状态
        if(w>h)swap(h,w);
        if((w*h)&1){printf("0\n");continue;}
        //calc dp[state][0]
        CL(dp,0);
        for(int i=0;i<(1<<w);i++){
            if(check(i))dp[i][0]=1;//row 0 合法状态
        }
        for(int j=1;j<h;j++){
            for(int i=0;i<(1<<w);i++){
                for(int k=0;k<(1<<w);k++){//可能可以优化
                    if(dp[k][j-1]&&ok(i,k)){
                        dp[i][j]+=dp[k][j-1];
                    }
                }
            }
        }
        //最后一层状态是1111111(全1)才有价值，如果出现0显然没有被填满
        printf("%lld\n",dp[(1<<w)-1][h-1]);
    }
    
    return 0;
}