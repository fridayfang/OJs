#include<bits/stdc++.h>
using namespace std;
struct match{
    int w[10010],l[10010];//存分数
    int pos;//存第几局
    int cnt1,cnt2;//胜局比
};
match m11,m21;
void init(match& ma){
    memset(ma.w,0,sizeof(ma.w));
    memset(ma.l,0,sizeof(ma.l));
    ma.pos=0;
    ma.cnt1=0;ma.cnt2=0;

}
int main(){
    char c;
    
    
    while(scanf("%c",&c)&&(c!='E')){
        if(c=='W'){
            //11 score
            m11.w[m11.pos]++,m21.w[m21.pos]++;;
            if(m11.w[m11.pos]>=11&&m11.w[m11.pos]>(m11.l[m11.pos]+1)){
                m11.pos++;
                m11.cnt1++;
            }
            if(m21.w[m21.pos]>=21&&m21.w[m21.pos]>(m21.l[m21.pos]+1)){
                m21.pos++;
                m21.cnt1++;
            }
            
        }
        if(c=='L'){
            m11.l[m11.pos]++,m21.l[m21.pos]++;
            if(m11.l[m11.pos]>=11&&m11.l[m11.pos]>(m11.w[m11.pos]+1)){//bug
                m11.pos++;
                m11.cnt2++;
            }
            if(m21.l[m21.pos]>=21&&m21.l[m21.pos]>(m21.w[m21.pos]+1)){
                m21.pos++;
                m21.cnt2++;
            }
        }

    }
    //output
    for(int i=0;i<=m11.pos;i++){
        //if(m11.w[i]!=0||m11.l[i]!=0||m11.pos==0) 
        printf("%d:%d\n",m11.w[i],m11.l[i]);

    }
    printf("\n");
    //printf("%d:%d\n\n",m11.cnt1,m11.cnt2);
    for(int i=0;i<=m21.pos;i++){
        //if(m21.w[i]!=0||m21.l[i]!=0||m21.pos==0) 
        printf("%d:%d\n",m21.w[i],m21.l[i]);

    }
    //printf("%d:%d\n",m21.cnt1,m21.cnt2);
    return 0;

}