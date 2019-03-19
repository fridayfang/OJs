# 单调队列 && 单调栈
## 单调队列
- 维护某个滑动区间的min or max,可用于dp的优化
- 以维护min为例，采用STL双端队列实现
- 每次加入元素x前
- 先检查队首元素==滑动后要删除的元素，如果是队收弹出
- 同时将队尾>x的元素都弹出
- 加入元素x,此时队收元素就是当前的Min
- [luogu1886](https://www.luogu.org/problemnew/show/P1886)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define name2str(name) (#name)
#define db(x) cout<<#x"=["<<(x)<<"]"<<endl
#define CL(a,b) memset(a,b,sizeof(a))
#define sf(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a)
#define rng(a) a.begin(),a.end()
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fr0(i,m) for(int i=0;i<m;i++)
#define fr1(i,m) for(int i=1;i<=m;i++)
//author:fridayfang
//date:19 3月 02
const double esp=1e-8;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6+5;
int a[maxn];
int n,k;
deque<int> q1;
deque<int> q2;
int main(){
    sf(n),sf(k);
    fr1(i,n) sf(a[i]);
    for(int i=1;i<=n;i++){
        if(!q2.empty()&&i>=k&&a[i-k]==q2.front()) q2.pop_front();
        while(!q2.empty()&&q2.back()>a[i]) q2.pop_back();
        q2.push_back(a[i]);
        if(i>=k) printf("%d ",q2.front());
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        if(!q1.empty()&&i>=k&&a[i-k]==q1.front()) q1.pop_front();
        while(!q1.empty()&&q1.back()<a[i]) q1.pop_back();
        q1.push_back(a[i]);
        if(i>=k) printf("%d ",q1.front());
    }

    return 0;
}
```

## 单调栈
- 我们先考虑单调增栈，即要求栈底到栈顶元素依次递增
- 如果加元素$a[i]=x$小于栈顶$a[j]$(栈只记录j值，下标)，则不断弹出栈顶元素，每次弹出的元素a[t](栈只是弹出t),则t右边第一个小于他的位置r[t]=i
-  而i左边第一个小于它的位置l[i]stack.front()
- leetcode42. Trapping Rain Water
```cpp
class Solution {
    public int trap(int[] height) {
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        while (i < height.length) {
            if (stack.isEmpty() || height[i] < height[stack.peek()]) {
                stack.push(i++);
            } else {
                int bottom = stack.peek();
                stack.pop();
                if (stack.isEmpty()) continue;
                int leftBound = stack.peek();
                int rain = (Math.min(height[leftBound], height[i]) - height[bottom]) * (i - leftBound - 1);
                res += rain;
            }
        }
        return res;
    } 
}
```