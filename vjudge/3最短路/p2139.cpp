#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 2月 27
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 300 + 5;
const int maxm = 1e6+5;
//floyd
int n,m;
int path[maxn][maxn];
int mp[maxn][maxn];
void floyd(){
    fr1(i,n) mp[i][i]=0;
    fr1(k,n){
        fr1(i,n){
            fr1(j,n){
                //经过1.2...k节点mp[i][j]最短路径
                if(mp[i][k]>=inf||mp[k][j]>=inf) continue;
                if(mp[i][j]>mp[i][k]+mp[k][j]){
                    mp[i][j]=mp[i][k]+mp[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    /*
    fr1(i,n){
        fr1(j,n){
            printf("%d->%d: %d\n",i,j,mp[i][j]);
        }
    }
    */
}

int cowin[maxn];

int main(){
    while(~scanf("%d %d",&n,&m)){
        CL(mp,0x3f);
        while(m--){
            int t;sf(t);
            for(int j=1;j<=t;j++)sf(cowin[j]);
            fr1(i,t)
            fr1(j,t){
                if(i!=j){
                    mp[cowin[i]][cowin[j]]=1;
                    mp[cowin[j]][cowin[i]]=1;
                }
            }
        }
        floyd();
        int ans=inf;
        fr1(i,n){
            int tmp=0;
            fr1(j,n){
                tmp+=mp[i][j];
            }
            ans=min(ans,tmp);
        }
        //cout<<ans*100/(n-1)<<endl;
        double avg=(ans+0.0)/(n-1.0);
        int fi=(int)(avg*100);
        
        printf("%d\n",fi);
    }
    return 0;


    
    return 0;
}