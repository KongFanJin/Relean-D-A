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

若$sum > 0$, 

- $sum+正数$变大,$sum+负数$变小
- `sum = max(sum,sum+e)`

若$sum <= 0$

- $负数+负数$需要取最大值,$负数+正数$无意义直接取正数即可
- `sum=e`

变大

- ++:sum + i > sum

变小

- +-:sum + i < sum
- --:sum + i < i

重新计数

- -+ : sum = i
- -- : sum = i

总结

- `sum < 0`时,`sum = i`
- `sum > 0`时,`max(sum+i,sum)`

# Code

