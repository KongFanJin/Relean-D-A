[LeetCode 53 Maximum Subarray](https://leetcode-cn.com/problems/maximum-subarray/)

[剑指 Offer 42. 连续子数组的最大和](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/)

参考

- [花花酱 LeetCode 53. Maximum Subarray](http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-53-maximum-subarray/)
- [整理一下看得懂的答案！！！](https://leetcode-cn.com/problems/maximum-subarray/solution/zheng-li-yi-xia-kan-de-dong-de-da-an-by-lizhiqiang/)

# 题目描述

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest `sum` and return its `sum`.

Follow up: 

- If you have figured out the $O(n)$ solution, try coding another solution using the divide and conquer approach, which is more subtle.

# Example

Example 1:

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

Example 2:

```
Input: nums = [1]
Output: 1
```

Example 3:

```
Input: nums = [0]
Output: 0
```

Example 4:

```
Input: nums = [-1]
Output: -1
```

Example 5:

```
Input: nums = [-2147483647]
Output: -2147483647
```

# **Constraints:**

- $1 <= nums.length <= 2 * 10^4$
- $-2^{31} <= nums[i] <= 2^{31} - 1$

# Analysis & Code

## 

## DP

`...,i-1,i,i+1,...`

### 分类讨论

`pre`记住上一轮的连续子序列最大和

若`sum(i-1) >= 0`

- `sum(i-1)+正数`,变大
- `sum(i-1)+负数`,变小
- 总结:需要确定`max(sum(i-1),sum(i-1)+nums[i])`是前进还是回退

若`sum(i-1) < 0`

- `sum(i-1) + 负数`,就变得更小了
  - 需要确定`max(sum(i-1),nums[i])`是回退还是重新开始
- `sum(i-1) + 正数`,反而抵消`正数`,`sum(i-1) + nums[i] < nums[i]` ,这样不如直接取`sum(i) = nums[i]`重新开始
- 总结:由于`pre`记住`sum(i-1)`,因此令`sum(i) = nums[i]`,然后`max(pre,sum(i))`等效于 `max(sum(i-1),nums[i])`

最后`pre = max(pre,sum(i))`

重复循环...

```C++
// https://leetcode-cn.com/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn/
class Solution {
   public:
    int maxSubArray(vector<int> nums) {
        int pre = nums[0];
        int sum = nums[0];

        for (auto element : nums) {
            if (sum > 0) { 
                sum += element;
            } else if (sum <= 0) { 
                sum = element;
            }
            
            pre = max(pre, sum); 
        } 

        return pre; // 为什么是pre不是sum?是因为要加入下一个元素(nums[n])时循环退出了
    }
};
```

### 不分类讨论

> 感觉类似斐波那契数列的迭代形式,刚开始学习DP,还不清楚DP是否都是这种形式

> 总结递推关系式/状态转移方程

```C++
// Author: Huahua
// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-53-maximum-subarray/
/**
 * 以num[i]为主来考虑(注num[i]+f(i-1)),而不是f(i-1)(注f(i-1)+num[i]),
 * num[i]+正数变大,num[i]+负数变小
 * 
 * 得递推关系式/状态转移方程: 
 * f(i) = f(i-1) > 0 ? num[i] + f(i-1) : num[i]
 * 
 * 模拟运行
 * nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * f    = [-2, 1, -2, 4,  3, 5, 6,  1, 5]
 * 
 * 思维转换
 * f[i] = max(nums[i] + f[i - 1], nums[i]) 与 f(i) = f(i-1) > 0 ? num[i] + f(i-1) : num[i]等价
 * 若nums[i] + f[i - 1] > nums[i],即f(i-1) > 0, f(i) = num[i] + f(i-1)
 * 若nums[i] + f[i - 1] < nums[i],即f(i-1) < 0, f(i) = num[i]
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 存储当前`nums[0:i]`的连续子序列最大和
        vector<int> f(nums.size()); 
        f[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
            f[i] = max(nums[i] + f[i - 1], nums[i]);
        
        return *std::max_element(f.begin(), f.end());
    }
};

// 改进,使用O(1)的空间复杂度
class SolutionX {
public:
    int maxSubArray(vector<int>& nums) {
        auto ans = nums[0];
        auto sum = nums[0];    
        for (int i = 1; i < nums.size(); ++i){
            sum = max(nums[i] + sum, nums[i]);
            // if(sum > ans) ans = sum;
            ans = max(sum, ans);
        }

        return ans;
    }
};
```

