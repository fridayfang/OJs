#include<bits/stdc++.h>
#define db(x) cout<<#x"=["<<(x)<<"]"<<endl
//#define db(x) cout<<#x"=["<<(x)<<"]"<<endl
using namespace std;
vector<int>p[5005];
int n,q,ans,sum,l[5005],r[5005],a[5005],s[5005],d[5005][5005];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1,x,y;i<=q;i++)scanf("%d%d",&l[i],&r[i]),a[l[i]]++,a[r[i]+1]--;
	for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        db(a[i]);
        sum+=a[i]>0;
        db(sum);
    }

	for(int i=1;i<=q;i++)
	for(int j=l[i];j<=r[i];j++)
	s[i]+=a[j]==1;
	for(int i=1;i<=n;i++)
	if(a[i]==2)
	{
		int t1=0,t2=0;
		for(int j=1;j<=q;j++)
		if(l[j]<=i&&i<=r[j])
		{
			if(!t1)t1=j;
			else t2=j;
		}
		d[t1][t2]++;
	}
	for(int i=1;i<q;i++)
	for(int j=i+1;j<=q;j++)
	ans=max(ans,sum-s[i]-s[j]-d[i][j]);
	printf("%d",ans);
}