---
tags:
    - 队列/双端队列
	- 滑动窗口/固定窗口
    - 困难
    - 剑指Offer第2版/59
    - LeetCode/239
created: 2020-10-21T20:22:15.495Z
modified: 2020-10-21T20:49:42.463Z题目[原指239](https://leetcode-cn.com/problems/sliding-window-maximum/
---
[题目原址-239](https://leetcode-cn.com/problems/sliding-window-maximum/)

参考

- [小美图解剑指Offer59题](https://www.bilibili.com/video/BV1YV411o7Gr/)
- [花花酱 LeetCode 239](https://www.bilibili.com/video/BV1WW411C763)
- [暴力法](https://leetcode-cn.com/problems/sliding-window-maximum/solution/c-bao-li-fa-shuang-duan-dui-lie-dp-by-yizhe-shi/)

# 题目描述

给定一个数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k `个数字。滑动窗口每次只向右移动一位。

要求:返回滑动窗口中的最大值。

# 示例

```
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值

---------------               -----

[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

# 提示

- $1 <= nums.length <= 10^5$
- $-10^4 <= nums[i] <= 10^4$
- $1 <= k <= nums.length$

# 进阶

你能在线性时间复杂度内解决此题吗？

# 初步分析

输出的数组大小为$nums.lengths-k+1$

# Brute Force

扫描每个滑动窗口的所有数字并找出其中的最大值.

## 代码

### 粗略代码

> 不涉及代码的格式等细节

```C++
int max (vector<int> win){	
	int m = win[0];
	for(auto i ; win){
		if(i > m) m = i;
	}
	return m;
} 

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> win{};
	vector<int> maxSW{};
	
	for(auto i = 0; i < nums.lengths-k; i++){
		for(auto j = i, m = 0; j < i + k; j++, m++)
			win[m] = nums[j];	
		
		maxSW[i] = max(win);
	}
}
```

错误分析



### 改版1

```c++
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> win{};
        vector<int> maxSW{};

        for (auto i = 0; i < nums.size() - k; i++)
        {
            for (auto j = i, m = 0; j < i + k; j++, m++)
                win[m] = nums[j];

            maxSW[i] = max(win);
        }

        return maxSW;
    }

    int max(vector<int> win)
    {
        int m = win[0];
        for (auto& i : win)
            if (i > m)
                m = i;
        
        return m;
    }
};
```

错误提示

```
Line 1034: Char 9: runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:9
```

错误分析

### 正确

```C++
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        vector<int> ans{};

        for (auto i = 0; i != nums.size() - k + 1; i++){
            int maxSW = nums[i]; // 默认窗口首元素最大
            for (auto j = i; j != i + k; j++)
                if(nums[j] > maxSW)
                    maxSW = nums[j];

            ans.push_back(maxSW);
        }

        return ans;
    }
};
```

leetcode测试数据集有的超时

## 时间/空间复杂度分析

二级循环:$T(n)=(n-k+1)k$

没有辅助空间

