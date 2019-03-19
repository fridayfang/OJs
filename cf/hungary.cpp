int linker[maxn];//只记录一边的点集
bool used[maxn];//记录同一边点集是否被加入交替路
int uN;
bool dfs(int u){//每次dfs成功意味匹配点增多，所以最多
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(!used[v]){
            used[v]=1;
            if(linker[v]==-1||dfs(linker[v])){
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary(){
    int res=0;
    CL(linker,-1);
    for(int u=0;u<uN;u++){//上一次匹配的点，dfs后依旧会被匹配，只是匹配的边变化了
        CL(used,0);
        if(dfs(u))res++;
    }
    return res;
}