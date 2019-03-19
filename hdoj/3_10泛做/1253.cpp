#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
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
//date:19 3月 10
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int K,A,B,C,T;
int mpp[55][55][55];
int vis[55][55][55];
struct node{
    int x,y,z,step;
    node(){}
    node(int _x,int _y,int _z,int _s):x(_x),y(_y),z(_z),step(_s){}
};
int mv[6][3]={{-1,0,0},{0,-1,0},{0,0,-1},{1,0,0},{0,1,0},{0,0,1}};
int bfs(){
    queue<node> q;q.push(node(0,0,0,0));vis[0][0][0]=1;
    while(!q.empty()){
        node tmp=q.front();q.pop();
        int cx=tmp.x,cy=tmp.y,cz=tmp.z,cs=tmp.step;
        //db(cx),db(cy),db(cz),db(cs);
        if((cx==A-1)&&(cy==B-1)&&(cz==C-1)&&cs<=T)return cs;
        if(cs>T)return -1;
        for(int i=0;i<6;i++){
            int nx=tmp.x+mv[i][0],ny=tmp.y+mv[i][1],nz=tmp.z+mv[i][2];
            if(nx>=0&&nx<A&&ny>=0&&ny<B&&nz>=0&&nz<C&&!vis[nx][ny][nz]&&mpp[nx][ny][nz]==0){
                vis[nx][ny][nz]=1;
                q.push(node(nx,ny,nz,cs+1));
            }
            
        }

    }
    return -1;

}


int main(){
    sf(K);
    while(K--){
        sf(A),sf(B),sf(C),sf(T);
        CL(vis,0);
        fr0(i,A){
            fr0(j,B){
                fr0(t,C){
                    sf(mpp[i][j][t]);
                }
            }
        }
        printf("%d\n",bfs());
    }
    
    return 0;
}