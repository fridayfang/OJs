#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct toy{
    int dir;
    string name;
};
toy ts[maxn];
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        cin>>ts[i].dir>>ts[i].name;
    }
    int x,y;
    int now=0;
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        if(ts[now].dir==x) now=(now+n-y)%n;
        else now=(now+y)%n;
    }
    cout<<ts[now].name<<endl;
    return 0;;
}