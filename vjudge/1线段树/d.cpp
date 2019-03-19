#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#define maxn 40010
using namespace std;
struct Node{
	int left,right;
	int type;
}data[maxn],de[4*maxn];
int N,ans;
bool vis[maxn];
vector<int>po,Map;
void BuildTree(int i,int left,int right)
{	de[i].left=left;
	de[i].right=right;
	de[i].type=-1;
	if(left==right)		return;
	int mid=(left+right)>>1;
	BuildTree(2*i,left,mid);
	BuildTree(2*i+1,mid+1,right);
}
void PushDown(int i)
{	if(de[i].left!=de[i].right&&de[i].type!=-1)
	{	de[2*i].type=de[2*i+1].type=de[i].type;
		de[i].type=-1;
	}
}
void Insert(int i,int left,int right,int cover)
{	if(left<=de[i].left&&de[i].right<=right)
	{	de[i].type=cover;
		return;
	}
	if(de[i].left==de[i].right)		return;
	PushDown(i);
	int mid=(de[i].left+de[i].right)>>1;
	if(right<=mid)		Insert(2*i,left,right,cover);
	else if(left>mid)	Insert(2*i+1,left,right,cover);
	else
	{	Insert(2*i,left,mid,cover);
		Insert(2*i+1,mid+1,right,cover);
	}	
}
void Query(int i,int left,int right)
{	if(de[i].type!=-1)
	{	vis[de[i].type]=1;
		return;
	}
	if(de[i].left==de[i].right)	return;
	int mid=(de[i].left+de[i].right)>>1;
	if(right<=mid)		Query(2*i,left,right);
	else if(left>mid)	Query(2*i+1,left,right);
	else
	{	Query(2*i,left,mid);
		Query(2*i+1,mid+1,right);
	}
}
void Solve()
{	int i,n,x,y;
	sort(po.begin(),po.end());
	po.erase(unique(po.begin(),po.end()),po.end());
	n=po.size();
	for(i=0;i<n-1;++i)
		if(po[i+1]-po[i]>1)
			po.push_back((po[i+1]+po[i])>>1);
	sort(po.begin(),po.end());		
	for(i=0;i<po.size();++i)
		Map.push_back(po[i]);
	BuildTree(1,0,po.size()-1);
	for(i=0;i<N;++i)
	{	x=lower_bound(Map.begin(),Map.end(),data[i].left)-Map.begin();
		y=lower_bound(Map.begin(),Map.end(),data[i].right)-Map.begin();
		Insert(1,x,y,data[i].type);
	}
	ans=0;
	memset(vis,0,sizeof(vis));
	Query(1,0,po.size()-1);
	for(i=0;i<N;++i)
		if(vis[i])
			ans++;
	printf("%d\n",ans);
}
int main()
{	int T,i;
	scanf("%d",&T);
	while(T--)
	{	scanf("%d",&N);
		po.clear(),Map.clear();
		for(i=0;i<N;++i)
		{	scanf("%d %d",&data[i].left,&data[i].right);
			data[i].type=i;
			po.push_back(data[i].left);
			po.push_back(data[i].right);
		}
		Solve();
	}
    return 0;
}