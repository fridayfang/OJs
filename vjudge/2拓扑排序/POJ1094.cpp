#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
using namespace std;
//author:fridayfang
//date:19 2月 23
//global varibles
#define ll long long;
#define inf 0x3f3f3f3f
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define sfs(c) scanf("%s",c)
#define pr(a) printf("%d\n",a)
#define db(a) printf("db %d\n",a)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
struct Edge{
    int u,v,nxt;
}es[900];
int cnt;
int head[26];
int deg[26],in[26];
char srt[26];
void add(int u,int v){
    //printf("db add edge %d %d\n",u,v);
    es[cnt].u=u,es[cnt].v=v,es[cnt].nxt=head[u];
    head[u]=cnt;
    in[v]++;
    cnt++;
}
int n,m;
char str[5];
bool flag;
int topo(){
    int idx=0;
    queue<int> q;
    fr0(i,n){
        if(deg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        if(q.size()>=2) flag=true;
        int tmp=q.front();
        q.pop();
        //printf("db %c\t",tmp+'A');
        srt[idx++]=tmp+'A';
        //
        for(int t=head[tmp];t!=-1;t=es[t].nxt){
            int u=es[t].u,v=es[t].v;
            deg[v]--;
            if(!deg[v]) q.push(v);
            //if((--deg[v])==0){
              //  q.push(v);
            //}
        }
    }
    //printf("idx %d\n",idx);
    for(int i=0;i<n;i++){
        if(deg[i]) return 1;//cycle inconsitence
    }
    if(!flag) return 2;//
    else return 3;

}


int main(){
    while(scanf("%d %d",&n,&m)&&n!=0){
        CL(srt,0);
        CL(in,0);
        CL(head,-1);
        cnt=0;
        int ans=0;
        bool incon=false;
        fr0(i,m){
            sfs(str);
            int u=str[0]-'A',v=str[2]-'A';
            add(u,v);
            flag=false;
            for(int i=0;i<n;i++){
                deg[i]=in[i];
            }
            if(incon) continue;
            ans=topo();
           // printf("db i %d ans %d\n",i,ans);
            if(ans==1){
                incon=true;
                printf("Inconsistency found after %d relations.\n",i+1);
            }
            else if(ans==2){
                incon=true;
                printf("Sorted sequence determined after %d relations: %s.\n",i+1,srt);
            }

        }
        if(!incon) printf("Sorted sequence cannot be determined.\n");


    }

    
    return 0;
}