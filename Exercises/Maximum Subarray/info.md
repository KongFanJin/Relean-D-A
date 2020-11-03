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

# Analysis

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

> 实际暗含了分类讨论
>
> 任何想到的呢?

忽略正负数的思考

`sum[i]`表示在遍历到数组的元素`num[i]`的连续子序列最大和

若`sum[i-1]+nums[i] > nums[i] `

- 令`sum[i] = sum[i-1]+nums[i]`,比较`sum[i]`与`sum[i-1]`
  - 若`sum[i] > sum[i-1]`,取`sum[i] = sum[i]`,产生一个连续子序列最大和
  - 若`sum[i] < sum[i-1]`,取`sum[i] = sum[i-1]`,产生一个连续子序列最大和

若`sum[i-1]+nums[i] < nums[i] `

- 令`sum[i] = nums[i]`,比较`nums[i]`与`sum[i-1]`
  - 若`nums[i] > sum[i-1]`,取`sum[i] = nums[i]`重新开始
  - 若`nums[i] < sum[i-1]`,取`sum[i] = sum[i-1]`,产生一个连续子序列最大和

```C++
// https://leetcode-cn.com/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn/
class Solution{
   public:
    int maxSubArray(vector<int> nums) {
        auto sum = nums[0];
        auto next = nums[0];

        for (auto i = 1; i != nums.size(); i++) {
            next = max(next + nums[i], nums[i]);
            sum = max(sum, next);
        }

        return sum;
    }
};
```

>  感觉类似斐波那契数列的迭代形式,刚开始学习DP,还不清楚DP是否都是这种形式

```C++

```



# Code

