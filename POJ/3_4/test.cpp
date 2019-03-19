#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#define inf 0x3f3f3f3f
#define ll long long
#define sscc ios::sync_with_stdio(false);
#define ms(a) memset(a,0,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define msi(a) memset(a,inf,sizeof(a))
using namespace std;

const int M=2e5+6;
int pre[M],ten,ans;//前向星 
int dfn[M],low[M],cens,vis[M];
stack <int> st;//栈 
int ns=0;//编号 
int nu[M];//存每个点对应的连通分量的编号 


struct A{
	int x,y,len,next;
}tens[M];//原来的点 

struct B{
	int y,len;
};

int pr[M];//prime存最小值 
vector<B> vt[M];//将缩点后的点存在vector里 

int add(int x,int y,int z)//前向星 
{
	tens[ten].x=x,tens[ten].y=y,tens[ten].len=z,tens[ten].next=pre[x];
	pre[x]=ten++;
}
int findd()//找pr数组最小值 
{
	int an=-1,s=inf;
	for(int i=1;i<=ns;i++)
		if(!vis[i]&&s>pr[i])
			s=pr[i],an=i;
	return an;
}

int prime(int v)//用prime把缩点之后的图跑一下，求最小生成树 
{
	memset(vis,0,sizeof(vis));
	memset(pr,inf,sizeof(pr));
	for(int i=0;i<vt[v].size();i++)
		pr[vt[v][i].y]=min(pr[vt[v][i].y],vt[v][i].len);//min的原因是缩点后两个点可能有多条路，取最小 
	vis[v]=1;
	pr[v]=0;
	int sum=0;
	for(int i=1;i<ns;i++)//遍历剩余n-1点 
	{
		int k=findd();
		if(k==-1)
			continue;
		vis[k]=1;
		for(int j=0;j<vt[k].size();j++)
		{
//			if(!vis[vt[k][j].y])//因为是有向图，把标记去掉 
				pr[vt[k][j].y]=min(pr[vt[k][j].y],vt[k][j].len);
		}
	}
	for(int i=1;i<=ns;i++) //找最小值 
		sum+=pr[i];
	return sum;
}

void tarjan(int v)//tarjan 算法 
{
	dfn[v]=low[v]=cens++,vis[v]=1,st.push(v);
	for(int i=pre[v];~i;i=tens[i].next)
	{
		int u=tens[i].y;
		if(dfn[u]==0)
		{
			tarjan(u);
			low[v]=min(low[v],low[u]);
		}else if(vis[u])
			low[v]=min(low[v],dfn[u]);
	}
	if(dfn[v]==low[v])
	{
		int j;
		ns++;
		do{
			j=st.top();
			st.pop();
			vis[j]=0;
			nu[j]=ns;//记住编号 
		}while(j!=v);
	}
}

int main()
{
	sscc;
	int n,m;
	while(cin>>n>>m)
	{
		mss(pre),ten=0,cens=1,ans=0;
		ms(dfn),ms(low),ms(vis),ns=0;
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
		}
		for(int i=0;i<n;i++)//跑一边tarjan，让全部连通分量编号 
		{
			vt[i].clear();
			if(!dfn[i])
				tarjan(i);
		}
		for(int i=0;i<m;i++)//缩点 
		{
			int x=tens[i].x;
			int y=tens[i].y;
			if(nu[x]!=nu[y])//如果不在同一个连通分量，那就是外边，也就是这条边就是prime要用的边 
				vt[nu[x]].push_back((B){nu[y],tens[i].len});//注意存的是缩点的编号 
		}
		cout<<prime(nu[0])<<endl;//prime跑一边找最小值 
	}
	return 0;
}