http://codeup.cn/problem.php?cid=100000585&pid=0

# 题目描述

输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）。

## 输入格式：

测试数据有多组，输入n(1<=n<=200)，接着输入n个数，然后输入x。

## 输出格式：

对于每组输入,请输出结果。

## 输入样例：

```
4
1 2 3 4
3
```

## 输出样例：

```
2
```

# 题解

## C++

```c++
#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::vector;
using std::ios_base;

const int maxN = 200;

int main(){
    ios_base::sync_with_stdio(false);

    vector<int> arr(maxN,0);

    int n,x;

    while(cin >> n)
        for(int i = 0 ; i != n - 1; i ++)
            cin >> arr[i];
    cin >> x;

    if( x - 1 >= 0 && x - 1 <= n)
        cout << arr[x - 1];

    return 0;
}
```
- 修改后
```C++
#include<iostream>
#include<vector>

// using std::cin;
// using std::cout;
// using std::vector;
// using std::ios_base;

using namespace std;

const int maxN = 200;

int main(){
    ios_base::sync_with_stdio(false);

    vector<int> arr(maxN,0);

    int n = 0,x = 0;

    while(cin >> n){
        for(int i = 0 ; i != n; i ++)
            cin >> arr[i];
        cin >> x;
    }

    bool flag = false;

    for(int i = 0; i != n; i++){
        if(x == arr[i]){
            cout << i;
            flag = true;
            break;
        }
    }

    if(!flag)
        cout << -1;

    return 0;
}
```

## 问题

- 先写大的框架,然后填写细节

- 先审题,看清题目要求

- Codeup平台显示错误,但是自己手动输入没问题,平台测试不显示错误提示,不知道错误的地方
- `EOF`
  - `Win`:`Ctrl + Z`
  - 类`Unix`:`Ctrl + D`

