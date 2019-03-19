#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 2? 27
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 500 + 5;
const int maxm = 250000+5;
struct Edge{
    int u,v;
    double dis;
    Edge(){}
    Edge(int _u,int _v,int _dis):u(_u),v(_v),dis(_dis){}
    bool friend operator < (Edge e1,Edge e2){
        return e1.dis< e2.dis;
    }
}es[maxm];

struct Point{
    int x,y;
}ps[maxn];
int cnt,s,n;
int fa[maxn];
int find(int u){
    return u==fa[u]?u:fa[u]=find(fa[u]);
}
double kruscal(){
    vector<Edge> ve;
    sort(es,es+cnt);
    int adde=0;
    for(int i=0;i<cnt;i++){
        int u=es[i].u,v=es[i].v;double dis=es[i].dis;
        int x=find(u),y=find(v);
        if(x!=y){
            //printf("db add %d %d %f\n",u,v,dis);
            ve.push_back(es[i]);
            fa[x]=y;
            adde++;
            if(adde>=n-1) break;
        }
    }
    int size=ve.size();
    int pos=size-s;
    return ve[pos].dis;
    
}

int main(){
    int t;sf(t);
    while(t--){
        sf(s),sf(n);
        fr1(i,n){sf(ps[i].x),sf(ps[i].y);}
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                double dis=sqrt((ps[i].x-ps[j].x)*(ps[i].x-ps[j].x)+(ps[i].y-ps[j].y)*(ps[i].y-ps[j].y));
                es[cnt].u=i,es[cnt].v=j,es[cnt].dis=dis,cnt++;
            }
        }
        //krucal
        fr1(i,n)fa[i]=i;
        double ans=kruscal();
        printf("%.2f\n",ans);

    }
    
    
    return 0;
}