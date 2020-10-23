---

tags:
    - 剑指Offer第2版/59
    - LeetCode/239
    - Queue/Deque
	- BST
	- Multiset
	- slidingwindow
    - hard
    - 未解决
created: 2020-10-21T20:22:15.495Z
modified: 2020-10-21T20:49:42.463Z
---
[题目原址-239](https://leetcode-cn.com/problems/sliding-window-maximum/)

参考

- 花花酱 LeetCode 239 [C++]
  - [video](https://www.bilibili.com/video/BV1WW411C763)
  - [code](https://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/)

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


# Brute Force

扫描每个滑动窗口的所有数字并找出其中的最大值.

## 代码



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

**错误分析**

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

**错误提示**

```
Line 1034: Char 9: runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:9
```

**错误分析**

# 代码参考

[跳转](Codes)

# 总结(待整理)

- 熟悉已有的工具(库)的性质
- 尽量要用现有工具解决问题

