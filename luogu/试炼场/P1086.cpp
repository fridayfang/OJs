#include<bits/stdc++.h>
using namespace std;
int m,n,k;
struct flower{
    int x,y;
    int num;
};
flower fs[410];
bool cmp(flower f1,flower f2){
    return f1.num>f2.num;
}

bool judge(flower f1,int& x,int& y,int& t){
    //当前位置x,y 能否摘下花生并返回
    //printf("in judge x %d y %d t %d\n",x,y,t);
    int time=(x==0&&y==0)?abs(f1.x-x)+1:abs(f1.x-x)+abs(f1.y-y)+1;
    int retime=time+f1.x;//摘花生+返回
    if(t>=retime){
        x=f1.x,y=f1.y,t=t-time;
        return true;
    }
    //printf("false x %d y %d t %d\n",x,y,t);
    return false;
}
int main(){
    scanf("%d %d %d",&m,&n,&k);
    //cout<<"k"<<k<<endl;
    int cnt=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int t;
            scanf("%d",&t);
            if(t!=0){
                fs[cnt].x=i,fs[cnt].y=j,fs[cnt].num=t;
                cnt++;
            }
        }
    }
    sort(fs,fs+cnt,cmp);
    int ans=0,x=0,y=0,t=k,i=0;
    //printf("before x %d y %d t %d\n",x,y,t);
    while(judge(fs[i],x,y,t)){
        ans+=fs[i].num;
        i++;
    }
    printf("%d\n",ans);
    return 0;
    

}