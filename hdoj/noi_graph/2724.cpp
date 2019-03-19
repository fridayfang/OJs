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
const int maxn = 1e2 + 5;
const int maxm = 1e6+5;
char mpp[maxn][maxn];
int n;
int bcnt,wcnt;
int judge(int x,int y){
    if(mpp[x][y]=='B')return 1;
    else if(mpp[x][y]=='W')return 2;
    else{
        for(int i=y+1;i<n;i++){
            if(mpp[x][i]=='B'){return 1;}
            if(mpp[x][i]=='W'){return 2;}
        }
        for(int i=y-1;i>=0;i--){
            if(mpp[x][i]=='B'){return 1;}
            if(mpp[x][i]=='W'){return 2;}

        }
        for(int i=x-1;i>=0;i--){
            if(mpp[i][y]=='B'){return 1;}
            if(mpp[i][y]=='W'){return 2;}
        }
        for(int i=x+1;i<n;i++){
             if(mpp[i][y]=='B'){return 1;}
            if(mpp[i][y]=='W'){return 2;}
        }

    }
    return -1;//no find

}


int main(){
    sf(n);
    fr0(i,n){scanf("%s",mpp[i]);}
    fr0(i,n){
        fr0(j,n){
            int ans=judge(i,j);
            if(ans==1)bcnt++;
            else if(ans==2)wcnt++;
        }
    }
    printf("%d %d\n",bcnt,wcnt);
    
    return 0;
}