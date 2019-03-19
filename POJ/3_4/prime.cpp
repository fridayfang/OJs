const int INF=0x3f3f3f3f;
const int maxn=110;bool vis[maxn];int lowc[maxn];
int prime(int cost[][maxn],int n){
    int ans=0;
    CL(vis,0); vis[0]=1;
    for(int i=1;i<n;i++) low[i]=cost[0][i];
    for(int i=1;i<n;i++){
        int minc=inf,p=-1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&minc>lowc[j]){
                minc=lowc[j],p=j;
            }
        }if(minc==inf) return -1;//原图不连通
    } 
}