#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int m,n;
struct que{
    int a[maxn];
    int size;
    int full;
    int point;

};
que q;
int main(){
    scanf("%d %d",&m,&n);
    memset(q.a,-1,sizeof(q.a));
    q.size=-1,q.full=m,q.point=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        int t;scanf("%d",&t);
        bool find=false;
        for(int j=0;j<=q.size;j++){
            if(t==q.a[j]){
                find=true;break;
            }
            
        }
        if(find) continue;
        else{
            //printf("not find %d\n",t);
            cnt++;
            q.point=(q.point+1)%q.full;
            q.a[q.point]=t;
            //printf(" add %d %d\n",q.point,t);
            if(q.size<q.full-1) q.size++;
        }
        //not find
        //judge is full

    }
    /*db
    cout<<q.size<<endl;
    for(int i=0;i<=q.size;i++){
        printf("%d\t%d",i,q.a[i]);
    }*/
    printf("%d\n",cnt);
    return 0;
}