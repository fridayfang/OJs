#include <bits/stdc++.h>
using namespace std;
//author:fridayfang
//date:19 2月 26
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 5000 + 5;
const int maxm = 20000+5;
vector<int> sta[maxn];
bool ontrain[maxm],comp[maxm];
int n,m;
int aa[maxm],bb[maxm];
int pos[maxn];
int a,b;
int cnt2;//统计剩余糖果>=2的站数
int solve(int begin){
    int cur=begin;
    int cnt=0,clk=0;
    while(cnt<m){
         //printf("cur %d cnt %d\n",cur,cnt);
         
        for(int i=1;i<=m;i++){
            //if(ontrain[i]) printf("on train %d  ",i);
            if(!comp[i]&&ontrain[i]&&bb[i]==cur){
                cnt++;
                comp[i]=1;
            }
        }
        //糖果到站
        //选取新糖果
        if(pos[cur]<sta[cur].size()){
                int t=pos[cur];
        
                int ca=sta[cur][t];
            ontrain[ca]=1;
            pos[cur]++;
        }
        cur=(cur+1>n)?(cur+1)%n:cur+1;
        if(cnt<m) clk++;
    }
    return clk;
}
bool cmp(int i,int j){
    int dis1=bb[i]>=aa[i]?bb[i]-aa[i]:bb[i]-aa[i]+n;
    int dis2=bb[j]>=aa[j]?bb[j]-aa[j]:bb[j]-aa[j]+n;
    return dis1>dis2;
}

int main(){
    sf(n),sf(m);
    fr1(i,m){
        sf(aa[i]),sf(bb[i]);
        //int dis=b>=a?b-a:b-a+n;
        sta[aa[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(sta[i].size()>=2) cnt2++;
        sort(sta[i].begin(),sta[i].end(),cmp);
    }
    CL(ontrain,0),CL(comp,0);
//    printf("%d\n",solve(1));
    for(int i=1;i<=n;i++){
        CL(ontrain,0),CL(comp,0);
        CL(pos,0);

        printf("%d ",solve(i));
    }

    return 0;
}