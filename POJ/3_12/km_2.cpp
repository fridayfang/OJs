/*
KM算法 O(n^3)
最大权匹配
点的编号从0开始
*/
const int N=310;
const int INF=0x3f3f3f3f;
int nx,ny;//两边点数
int g[N][N];//二分图描述
int linker[N],lx[N],ly[N];//
int slack[N];
bool visx[N],visy[N];
bool dfs(int x){
    visx[x]=true;
    for(int y=0;y<ny;y++){
        if(visy[y])continue;
        int tmp=lx[x]+ly[y]-g[x][y];
        if(tmp==0){
            visy[y]=true;
            if(linker[y]==-1||dfs(linker[y])){
                linker[y]=x;return true;
            }
        }
        else if(slack[y]>tmp)slack[y]=tmp;//min slack[y]
    }
    return false;
}
int km(){
    CL(linker,-1),CL(ly,0);
    for(int i=0;i<nx;i++){
        lx[i]=-inf;
        for(int j=0;j<ny;j++){//如果有边不可连-inf
            if(g[i][j]>lx[i])lx[i]=g[i][j];
        }
    }
    for(int x=0;x<nx;x++){
        CL(slack,inf);
        while(true){
            CL(visx,0),CL(visy,0);
            if(dfs(x))break;
            int d=inf;
            for(int i=0;i<ny;i++){
                if(!visy[i]&&d>slack[i])d=slack[i];
            }
            for(int i=0;i<nx;i++){
                if(visx[i])lx[i]-=d;
            }
            for(int i=0;i<ny;i++){
                if(visy[i])ly[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    int res=0;
    for(int i=0;i<ny;i++){
        if(linker[i]!=-1)res+=g[linker[i]][i];

    }
    return res;
}