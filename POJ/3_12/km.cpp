/*
二分图带权匹配:KM算法 / 最小费用最大流
完备匹配: |M|=min{|X|,|Y|}
最佳匹配: 完备匹配的基础上 min or max w(|M|)
最大权匹配:不要求是完备匹配

KM：融合了贪心和引入可行顶标



*/
const int qwq=0x7fffffff
int w[1000][1000];//w数组记录边权值
int line[1000],usex[1000],usey[1000],cx[1000],cy[1000];
//line[i] 记录右边端点i连的左端点
//usex,usey
//cx,cy记录点的顶标
int n,m,ans;//n left m right
bool find(int x){
    usex[x]=1;
    for(int i=1;i<=m;i++){
        if((usey[i]==0)&&cx[x]+cy[y]==w[x][i]){//边的存在条件
            usey[i]=1;
            if(line[i]==0||find(line[i])){
                line[i]=x;return true;
            }
        }
    }
    return false;
}
int km(){
    for(int i=1;i<=n;i++){//分别对左边的点依次匹配
        while(true){
            int d=qwq;CL(usex,0),CL(usey,0);
            if(find(x))break;//直到成功匹配才换下一个点匹配
            for(int j=1;j<=n;j++){
                if(usex[j]){//增广路上的点
                    for(int k=1;k<=m;k++){
                        if(!usey[k])d=min(d,cx[j]+cy[k]-w[j][k]);//calc d
                    }
                }
            }
            if(d==qwq)return -1;//不存在完备匹配
            //对增广路上的点+-d
            for(int j=1;j<=n;j++){
                if(usex[j])cx[j]-=d;
            }
            for(int j=1;j<=m;j++){
                if(usey[j])cy[j]+=d;
            }
        }
    }
    ans=0;
    for(int i=1;i<=m;i++)ans+=w[line[i]][i];
    return ans;

}