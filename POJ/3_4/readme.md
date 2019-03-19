# tarjan强连通分量-缩点利器
## 算法思想
- 通过一次dfs将有向图分为不同的强连通分量(SCC)
- 图可能本身不连通所以一般多次tarjan
- dfn[n],low[n]两个数组:   
定义 DFN(u)为结点 u 搜索的次序编号(时间戳)， Low(u)为 u 或 u 的子树（经过最多一条
后向边或栈中横叉边） 能够回溯到的最早的栈中结点的次序号。 由定义可以得出:
Low(u)=Min    
{   
DFN(u),   
Low(v),(u,v)为树枝边， u 为 v 的父结点  
DFN(v),(u,v)为后向边或指向栈中结点的横叉边  
}  
- 为什么是一条?这是和割点和桥区分的
- 后向边和栈中横叉边，注意实现
- 强连通分量的条件low[u]==dfn[u],而且此时的性质是u一定在栈底
- 至于原理很难想清楚唉，毕竟是tarjan大神的算法，%%%
- 重要性在于:减少了点,得到了一个有向无环图(就是可以拓扑排序,求最大路径的那个图)
- 缩点第二法是并查集
### 模板
```cpp
void tarjan(int u){
    dfn[u]=low[u]=(++timing);
    st.push(u),ins[u]=1;
    for(int t=head[u];t!=-1;t=es[t].nxt){
        int v=es[t].v;
        if(!dfn[v]){tarjan(v);low[u]=min(low[u],low[v]);}
        else if(ins[v]){low[u]=min(low[u],dfn[v]);}
    }
    if(dfn[u]==low[u]){
        int j;colcn++;
        do{
            j=st.top(),st.pop(),ins[j]=0,col[j]=colcn;
        }while(j!=u);
    }

}
```
- col[]是对节点染色,将强连通分量染成同一色
- 可以盲打模板的题:[POJ2186]
