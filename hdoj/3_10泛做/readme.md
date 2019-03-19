## 惨痛教训
### 
在调试Bug的错误
- min,max可自己宏定义
- 也可调用<algorithm>库中的
- 一些博客说明:[blog1](https://blog.csdn.net/sleepp/article/details/81876502),[blog2](https://blog.csdn.net/jk110333/article/details/8021231),[blog3](https://blog.csdn.net/a_ran/article/details/74911031)
```cpp
//version 1 ok
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
//version 2 会引发严重错误,十级警告
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
//建议也可用std::min or 自己写inline int min(int a,int b)
//建议版本1也弃用，真的会引发未知错误

```
