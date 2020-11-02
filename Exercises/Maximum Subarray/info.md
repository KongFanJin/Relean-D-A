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

`sum+nums[i]`与`sum`

若`sum >= 0`

- `sum+正数`,​变大
- `sum+负数`,变小
- `sum = max(sum,sum+nums[i])`

若`sum < 0​`

- `sum + 负数`,就变得更小了
  - 这时是取`sum = sum`,还是`sum = num[i]`?由于是子序列,不能跳格,故`sum = num[i]`,要重新开始
- `sum + 正数`,反而抵消`正数`,`sum + nums[i] < nums[i]` ,这样不如直接取`sum = nums[i]`
- 故`sum = nums[i]`

# Code

