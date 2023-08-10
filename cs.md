#数论

https://zhuanlan.zhihu.com/p/449221995

# 定义

## 单位元

【定义1】在一个集合中，对于某种运算 $∗$（注意：这里代表通用运算的表示符号，并不是特指乘法），如果对于任何的集合元素 $a$ ，和元素 $e$ 运算，得到还是集合元素 $a$ 本身，则称 $e$ 为这个运算下的单位元。

例如:
在加法中，任意实数 $a$ ，都有 $a+e=e+a=a$ ，及单位元 $e=0$

在乘法中，任意实数 $a$ ，都有 $a\times e=e\times a=a$ ，及单位元 $e=1$

## 逆元

【定义2】在一个集合中，对于某种运算 $*$ ，如果任意两个元素的运算结果等于单位元，则称这两个元素互为逆元。

例如:
在加法中，任意实数 $a$ 的逆元为 $-a$

在乘法中，任意非零实数 $a$ 的逆元为 $a^{-1}$ 或 $\frac{1}{a}$

## 模乘的单位元

所有模 $n$ 和 $a$ 同余的数都可以表示成
$$a(mod\ n) \equiv kn+a(k\in \mathbb{Z})$$

经过一系列变化，可得到模乘的单位元是 $1(mod\ n)$

## 模乘的逆元

任意整数 $a(mod\ n)$ 的逆元表示为
$$a^{-1}(mod\ n)$$
并且根据逆元的定义，满足:
$$aa^{-1}\equiv1(mod\ n)$$
因此，$a$ 的逆元为 $a^{-1}$

# 逆元求解

## 拓展欧几里得定理

【例题1】给定正整数 $a$ 和 $b$，求满足等式 $ax+by=1$ 的 $x$ 的最小正整数解。如果不存在返回 $-1$ 。
    首先，我们需要提取 $a$ 和 $b$ 的最大公约数，即令 $g=gcd(a,b)$ ，则原等式可以转化为：
    
$$g(\frac{a}{g}x+\frac{b}{g}y)=1$$
两个整数相乘等于 1，则他们要么都等于 1，要么都等于 −1，又因为任何两个数的最大公约数不可能为负数，所以 $g=1$。  
所以当 $a$ 和 $b$ 不互素时，逆元必定不存在，直接返回 −1； 
那么，我们只需要考虑 $a$ 和 $b$ 互素的情况。  
给出以下推导式：
$$ax+by=1$$
$$=gcd(a,b)$$
$$=gcd(b,a\ mod\ b)$$
$$=bx'+(a\ mod\ b)y'$$
$$=bx'+(a-b\left \lfloor \frac{a}{b} \right \rfloor)y'$$
$$=ay'+b(x'-\left \lfloor \frac{a}{b} \right \rfloor y')$$
- (1) 题目给定的等式；
- (2) $a$ 和 $b$ 互素，则 $1=gcd(a,b)$；
- (3) 最大公约数的辗转相除法，即欧几里德定理；
- (4) $gcd(a,b)=ax+by$，将 $b$ 代入 $a$，$(a\ mod\ b)$ 代入 $b$ 得到 $bx'+(a\ mod\ b)y'$；
- (5) 根据取模的定义，有：$a\ mod\ b=(a-b\left \lfloor \frac{a}{b} \right \rfloor)$；（其中 $\lfloor x\rfloor$ 代表 $x$ 的下整）
- (6) 按照 $a$ 和 $b$，合并同类项；

得到：
$$ax+by=ay'+b(x'-\lfloor \frac{a}{b} \rfloor y')$$
将和 $a$ 相乘的部分看成 $a$ 的系数，和 $b$ 相乘的部分看成 $b$ 的系数，从而得到：
$$\left\{\begin{matrix}x=y'
 \\y=x'-\lfloor \frac{a}{b} \rfloor y'
\end{matrix}\right.$$
```cpp
#define ll long long

ll ExpGcd(ll a, ll b, ll &x, ll &y) {
    ll q, temp;
    if( !b ) {
        q = a; 
        x = 1; 
        y = 0;
    }else {
        q = ExpGcd(b, a % b, x, y);
        temp = x; 
        x = y;
        y = temp - (a / b) * y;
    }
    return q;
}
```

【例题2】给定正整数 $a$ 和 $n$，求满足等式 $ax\equiv 1(mod\ n)$ 的 $x$ 的最小正整数解。如果不存在，则返回 $-1$。

这就是一个求逆元的题。$x$ 就是 $a$ 在模 $n$ 乘法上的逆元。  
我们将 $ax\equiv 1(mod\ n)$换一种表达形式，如下：
$$ax=kn+1(k\in \mathbb{Z})$$
移项得：
$$ax-kn=1$$
由于 $k$ 为整数，无论正负，由此表达式变成
$$ax+kn=1$$
这时候我们发现，只要将 $k$ 用 $y$ 表示，$n$ 用 $b$ 表示，就变成了如下表达式：
$$ax+by=1$$
转化成了 【例题1】 的问题。所以，利用扩展欧几里德定理，我们可以把逆元的求解用如下函数实现：

```cpp
ll Inv(ll a, ll n) {
    ll x, y;
    ExpGcd(a, n, x, y);    // (1)
    x = (x % n + n) % n;   // (2)
    return x;
}
```

- (1) 利用扩展欧几里得计算 $x$ 的一个可行解；
- (2) 将 $x$ 转化成最小的模 $n$ 同余的正整数；

## 费马小定理

【例题3】给定素数 $a$ 和 正整数 $p$，求满足 $ax\equiv 1(mod\ p)$ 的最小正整数 $x$ ，如果不存在返回 $-1$ 。

【例题3】和【例题2】的区别就是：模数变成了素数。所以我们可以利用费马小定理来求逆元。  
首先，当 $a$ 为 $p$ 的倍数时， $ax\equiv 0(mod\ p)$ ，所以一定不存在，直接返回 $−1$；否则，根据费马小定理，我们可以知道：

$$a^{p-1}\equiv 1(mod\ p)$$
可得到
$$a\times a^{p-2}\equiv 1(mod\ p)$$

对比原式，逆元 $x$ 满足：
$$x=a^{p-2}(mod\ p)$$
利用二分快速幂求解即可，c++ 代码实现如下：

```cpp
#define ll long long
ll Exp(ll a,ll n, ll mod){
    ll ans = 1;
    while(n) {
        if(n & 1) 
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

ll Inv(ll a, ll p) {
    return Exp(a, p-2, p);
}
```
[例题:P1641 [SCOI2010] 生成字符串](https://www.luogu.com.cn/blog/user35379/solution-p1641)


