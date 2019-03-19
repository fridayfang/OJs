#include<bits/stdc++.h>
 
using namespace std;
 
int mod = 10007;
const int MAXN = 100000 + 10;
int a[4 * MAXN] , flag[4 * MAXN];
 
void Union(int k , int l , int r)
{
    if(!flag[l] || !flag[r])
        flag[k] = 0;
    else if(a[l] != a[r])
        flag[k] = 0;
    else
    {
        flag[k] = 1;
        a[k] = a[k << 1];
    }
}
void update(int rt ,int l , int r, int x , int y , int c ,int q)
{
    if(l >= x && r <= y && flag[rt])
    {
        if(q == 1)
            a[rt] = (a[rt] + c) % mod;
        else if(q == 2)
            a[rt] = (a[rt] * c % mod) % mod;
        else
            a[rt] = c;
        return;
    }
    if(flag[rt])
    {
        flag[rt << 1] = flag[rt << 1 | 1] = 1;
        a[rt << 1] = a[rt << 1 | 1] = a[rt];
        flag[rt] = 0;
    }
    int mid = (l + r) >> 1;
    if(mid >= x)
        update(rt << 1 , l , mid , x , y , c , q);
    if(mid < y)
        update(rt << 1 | 1 , mid + 1 , r , x , y , c , q);
    Union(rt , rt << 1 , rt << 1 | 1);
}
 
int query(int rt , int l , int r , int x , int y , int c)
{
    if(flag[rt] && l >= x && r <= y)
    {
        int ans = 1;
        for(int i = 1; i <= c ; i ++)
            ans = ( ans * a[rt] ) % mod;
        ans = (ans * (r - l + 1)) % mod;
        return ans;
    }
    if(flag[rt])
    {
        flag[rt << 1] = flag[rt << 1 | 1] = 1;
        flag[rt] = 0;
        a[rt << 1] = a[rt << 1 | 1] = a[rt];
    }
    int mid = (l + r) >> 1;
    int ans = 0;
    if(mid >= x)
        ans += query(rt << 1 , l , mid , x , y , c);
    if(mid < y)
        ans += query(rt << 1 | 1 , mid + 1 , r , x , y , c);
    return ans % mod;
}
int main()
{
    int n , m ;
    int q , x , y , c ;
    while(scanf("%d %d" , &n , &m)&&(n!=0))
    {
        memset(flag , 1 , sizeof(flag));
        memset(a , 0 , sizeof(a));
        while(m --)
        {
            scanf("%d %d %d %d" , &q , &x , &y , &c);
            if(q <= 3)
                update(1 , 1 , n , x , y , c, q);
            else
                printf("%d\n" ,query( 1 , 1 , n , x , y , c));
        }
    }
    return 0;
}