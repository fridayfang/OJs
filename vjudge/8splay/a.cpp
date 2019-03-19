
const int maxn=100010;
struct Node{
    Node* ch[2],*fa;
    int size;
    int rev;
    Node(){ch[0]=ch[1]=fa=null;rev=0;}
    inline void push_up(){
        if(this==null)return ;
        size=ch[0].size+ch[1].size+1;
    }
    inline void setc(Node* p int d){

    }
}


struct Node{
    int ch[2],ff,cnt,val,son;
}t[maxn];
void push_up(int u){
    int x=t[u].ch[0],y=t[u].ch[1];
    t[u]=son=t[x].son+t[y].son+t[u].cnt;
}
void rot(int x){//旋转
    int y=t[x].ff,z=t[y].ff;
    int k=(t[y].ch[1]==x);//确定x是左儿子还是右儿子
    t[z]
}