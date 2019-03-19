#include <bits/stdc++.h>
using namespace std;
//author:fridayfang
//date:19 2月 25
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
char mp[55][55];
int vis[55][55];
int r1,c1,r2,c2,n;
int mv[6][2]={{1,0},{-1,0},{0,1},{0,-1},{0,0}};
int dis(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
struct Point{
    int x,y;
    //Point(){}
    Point(int x_,int y_):x(x_),y(y_){}
};
vector<Point> v1,v2;
void dfs(int x,int y, vector<Point>& v){
    v.push_back(Point(x,y));
    fr0(i,4){
        int a=x+mv[i][0],b=y+mv[i][1];
        if(!vis[a][b]&&mp[a][b]=='0'){
            vis[a][b]=1;
            dfs(a,b,v);
        }
    }
    
}
int main(){
    sf(n),sf(r1),sf(c1),sf(r2),sf(c2);
    fr1(i,n){
        scanf("%s",mp[i]+1);
    }
    int mindis=0x3f3f3f3f;
    dfs(r1,c1,v1);
    dfs(r2,c2,v2);
    
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            int x1=v1[i].x,y1=v1[i].y;
            int x2=v2[j].x,y2=v2[j].y;
            //printf("db %d %d %d %d",x1,x2,y1,y1);
            mindis=min(mindis,(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
    }
    pr(mindis);
    return 0;
}