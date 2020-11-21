# 级数 $\frac{x^n}{n!}$

$S(x) = 1 + x + \frac{x^2}{2!} + \frac{x^2}{2!} + \frac{x^3}{3!}+\cdots+\frac{x^n}{n!}$,直到$\frac{x^n}{n!} < 10^{-6}$

分析

- 第`n`项:$T_n = \frac{x^n}{n!}$
- 第`n+1`项:$T_{n+1} = \frac{x^{n+1}}{(n+1)!} = \frac{x}{n+1}T_n$
- 得递推式:
  - $T_{n+1} = \frac{x}{n+1}T_n$
  - $T_0=1$

## 递归法

```C++
#include <cmath>

double s(double x){
	if()
}
```

## 递推法/迭代法

```C++
#include <cmath>

double s(double x){
    double s = 1.0, t = 1.0;
    int n = 1;
    
    while(fabs(t) > 1e-6){
        t *= x/(n+1);
        s = s + t;
        n++
    }
    
    return s;
}
```



# 级数 $\frac{n}{(n+1)\times(n+2)!}$

$f(n) = \frac{0}{1\times2!}+\frac{1}{2\times3!}+\frac{2}{3\times4!}+\frac{3}{4\times5!}+\cdots+\frac{n}{(n+1)\times(n+2)!}$

分析

- $T(n) = \frac{n}{(n+1)\times(n+2)!}$
- $(n+2)! = (n+2)(n+1)!$

## 递归法

```C++
double f1(int n){
    int Tn = 0;
	if(n == 0)
        return 0;

     Tn = n/((n+1)f2(n+2));
     n -= 1;
     return f(n-1) + Tn;
}

int f2(int n){
    int s = 1;
	while(n > 1){
    	s *= n;
        n--;
    }
}
```

## 迭代法

```C++

```

