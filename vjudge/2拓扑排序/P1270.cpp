#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//author:fridayfang
//date:19 2月 24
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
int mp[30][30],deg[30],vis[30],out[30];//init -1
char str[100];
//遍历拓扑排序所有可能
int n;
void dfs(int num){//num记录已经存储第几个了
    if(num==n){
        //出口
        for(int i=0;i<n;i++){
            printf("%c",'a'+out[i]);
        }
        printf("\n");
        return ;
    }

    for(int i=0;i<26;i++){
        
        if(deg[i]==0&&!vis[i]){
            //删掉点
            for(int j=0;j<26;j++){
                if(mp[i][j]==1){
                    deg[j]--;
                }
            }

        
            vis[i]=1;
            out[num]=i;
            dfs(num+1);
            //恢复状态
            vis[i]=0;
            for(int j=0;j<26;j++){
                if(mp[i][j]==1){
                    deg[j]++;
                }
            }


        }
    }



}

int main(){
    while(gets(str)!=NULL){
        CL(deg,-1),CL(mp,0),CL(vis,0);
        int cnt=0;
        for(int i=0;i<strlen(str);i++){
            if(str[i]>='a'&&str[i]<='z'){
                int x=str[i]-'a';
                deg[x]=0;
                cnt++;
            }
        }
        n=cnt;
        gets(str);
        int pos=0;
        int tmp[100];
        for(int i=0;i<strlen(str);i++){
            if(str[i]>='a'&&str[i]<='z'){
                tmp[pos++]=str[i]-'a';
            }
        }
        for(int i=0;i<pos;i+=2){
           // printf("add %c %c\n",tmp[i]+'a',tmp[i+1]+'a');
            mp[tmp[i]][tmp[i+1]]=1;
            deg[tmp[i+1]]++;
        }
        dfs(0);
        printf("\n");

    }
    return 0;
    
}