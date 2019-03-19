# Educational Codeforces Round 61 (Rated for Div. 2) 题解
## 教育场真的好好教育了我(原来教育场是 7problems/2h)
## A. Regular Bracket Sequence
### 题意
给出四组"((","()",")(","))"的个数，判断能否排成能够匹配的括弧
### 思路
- 观察知:1,4类型的括弧数量应相等
- 如果有1,4类型的括弧存在，则3类型的可以有无限个，即放在1，4类型中间
- 2类型括弧不影响
### 实现细节(略)

## B. Discounts
### 题意
折扣$q_i$会免掉$q_i-1$贵的钱，排序即可解决
### 实现细节(略)

## C. Painting the Fence
### 题意
给出n个线段，求(n-2)个线段所能覆盖的最大长度
### 思路
- 看起来好像线段树的变种题目:
    - 先对n个线段建树，然后枚举删除的两条边
    - 可以维护长度和覆盖的次数(应该能行)?
    - 删边的话就是整个区段-1
    - 复杂度O(N^2logN)(N=5000)>1e8
    - 很可能被卡掉
- 在讲到n个线段覆盖长度的问题实际上有一种简单方法，打标记+前缀和
    - a[l]++,b[r+1]--;
    - 这样前缀和sum[i]能表示[i]被覆盖的次数
    - 那么如何删边呢？我们只需要删除边上sum[i]=1的区域，因为sum[i]>1的区域有多条线段覆盖
    - 这里的实现细节可以去处理边缩成sum[i]=1的区域
    - 最后一个问题:我们要删除两条边，如果sum[i]>1的区域恰好都在这两条边内，岂不是应该删去而没有删
    - 所以我们可以枚举所有的点sum[i]==2,然后枚举边是否在两条边中，并用len[i][j]记录线段i,j重合区域长度
    - 复杂度:O(N^2)(N=5000)
### 实现细节
```cpp
//只列核心代码
int n,q;
int l[maxn],r[maxn],a[maxn];
int len[maxn];//??????????????
int dp[maxn][maxn];
int sum;//
int main(){
    cin>>n>>q;
    fr1(i,q){cin>>l[i]>>r[i];a[l[i]]++,a[r[i]+1]--;}//打标记
    fr1(i,n){a[i]+=a[i-1];if(a[i]>0)sum++;}//前缀和a[],sum记录q个painter覆盖长度
 
    for(int i=1;i<=q;i++){//记录每个painter的长度
        for(int j=l[i];j<=r[i];j++){
            if(a[j]==1) len[i]++;
        }
    }
    //??????????
    for(int i=1;i<=n;i++){//统计2次覆盖的情况
        if(a[i]==2){
            int p1=0,p2=0;
            for(int j=1;j<=q;j++){
                if(l[j]<=i&&i<=r[j]){
                    if(p1==0)p1=j;
                    else p2=j;
                }
            }
            dp[p1][p2]++;//p2>p1
        }
    }
    //?????????
    int ans=0;
    for(int i=1;i<=q;i++){
        for(int j=i+1;j<=q;j++){
            ans=max(ans,sum-len[i]-len[j]-dp[i][j]);
        }
    }
    pr(ans);
    return 0;
}
```
## D. Stressful Training
### 题意
n台电脑,初始电量$a_i$,每分钟小号电量$b_i$,需要坚持k分钟(通过样例分析似乎是k-1分钟,或者说是每台电脑分钟的开始有电即可),问需要最少买多大功率的充电器(买一台，轮流充)
### 思路
- 我最开始的思路是:怎么求最大功率-->难道是数学方法-->可这么多台怎么求-->难道可以看作一台-->将情况分成1.任何功率都无法满足2.可以满足,然后将所有电脑看成整体-->1.可以通过找某分钟出现两台无法满足的电脑即可判断,2.数学方法
- 结果WA WA WA(虽然不会做但还是很有想象力的不是吗)

- 正确的思路:二分答案(无法数学求出答案的问题就二分啊)
- 二分之后，对答案的check()贪心处理，即每次选择能坚持时间最短的laptop进行充电(贪心有理)
- 一个优化，可以使用优先队列，当充电后可坚持时间>k,即可不用再入队列

### 细节实现
```cpp
const int maxn = 2e5 + 5;
const int maxm = 1e6+5;
ll a[maxn],b[maxn];
int n,k;
struct lap{
    ll a,b,minu;//minu 表示坚持的分钟
    friend bool operator <(lap l1,lap l2){
        return l1.minu>l2.minu;//for min heap
    }
}laps[maxn];
//二分答案，然后求解
bool check(ll p){
    //db(p);
    priority_queue<lap> pq;
    for(int i=1;i<=n;i++){
        laps[i].a=a[i],laps[i].b=b[i],laps[i].minu=a[i]/b[i];//
        pq.push(laps[i]);
    }
    for(int i=1;i<k;i++){//i: minutes
        lap need=pq.top();//the laptop need charge
        pq.pop();
        need.a+=p,need.minu=need.a/need.b;
        if(need.a/need.b<k){//还需充电的入heap
            pq.push(need);
        }
        //check any remain lack of power
        if(pq.empty()){return true;}//优化
        lap need2=pq.top();
        if(need2.minu<i){//db(i),db(need2.minu);
        return false;}//无法坚持到i minutes
    }
    return true;
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    fr1(i,n)scanf("%lld",&b[i]);
    ll lo=0,hi=1e13,mid;
    while(lo<hi){
        mid=(lo+hi)>>1;
        if(!check(mid)){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(lo==1e13)printf("-1\n");
    else printf("%lld\n",lo);
    return 0;
}
```
## E. Knapsack
### 题意
- 教育场就很有教育意义，从k重背包又变种出题目
- 只有1..8种重量物品，给出数量$cnt_1..cnt_8$,背包容量W，问如何使其尽可能装满
- 核心:$W<=1e18,cnt_i<=1e16$
- 能够对背包容量起关键作用是小数量的物品,在还未装满的情况下留下一些小数量的物品用于dp即可(大概是这个思路，至于这个小数量是多少呢?有人认为跟lcm(1,2,3...8)有关，只是猜想)
- 是不是很难理解，但体会到上面的思想就能解出此题
### code
```cpp
ll a[10];
ll v;
ll dp[maxn];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int getlcm(int a,int b){
    return a*b/gcd(a,b);
}
//lcm(1,2...8)=840
int main(){
    ll sum=0;
    int lcm=1;
    cin>>v;fr1(i,8){cin>>a[i];sum+=a[i]*i;}
    //db(lcm);
    if(sum<=v){cout<<sum<<endl;return 0;}
    ll ans=0;//记录已加和
    ll res=v;//记录还需凑成的容积
    for(int i=1;i<=8;i++){
        ll add=min(a[i],res/i);//记录所需和剩余的较小值
        ll radd=max(add-(840),0);//最多留下840个items
        ans+=i*radd;
        res-=i*radd;
        a[i]=a[i]-radd;
        //db(a[i]);
    }
    //db(ans),db(res);
    //经过处理所有次数不超过100
    //也保证了res不会超过840*(1+2+3+..+8)=2e4
    dp[0]=0;
    ll maxcap=0;
    for(int i=1;i<=8;i++){//complexity:2e4*8*840=1e8
        for(ll j=res;j>=0;j--){
            for(int k=0;k<=a[i];k++){
                if(j>=k*i)dp[j]=max(dp[j],dp[j-k*i]+k*i);//空间j最大能装的容积
                else break;
            }
        }
    }
    
    ans+=dp[res];
    cout<<ans<<endl;
    return 0;
}
```
## F. Clear the String
### 题意
lrj箱子问题的简化版本，区间dp可做
### code
```cpp

const int N=505;
int dp[N][N];
string s;
int n;
int call(int lft,int rgt){//区间dp
    if(lft>rgt) return 0;
    if(lft==rgt){return 1;}
    if(dp[lft][rgt]!=-1)return dp[lft][rgt];
    int ans=call(lft+1,rgt)+1;
    for(int nxt=lft+1;nxt<=rgt;nxt++){
        if(s[nxt]==s[lft]){
            ans=min(ans,call(lft+1,nxt-1)+call(nxt,rgt));
        }
    }
    return dp[lft][rgt]=ans;
}
int main(){
    CL(dp,-1);cin>>n>>s;
    int ans=call(0,n-1);
    cout<<ans;
}
```
## G. Greedy Subsequences
### 不会啊WA
## rating++,意料之外的事情，大概有太多人在E题被hack