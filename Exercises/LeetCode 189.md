来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array

### 问题描述

给定一个数组，将数组中的元素向右移动 `k`个位置，其中 `k`是非负数。

**示例 1:**

```
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
```

**示例 2:**

```
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
```

**说明:**

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。

### 分析

#### 方法一

`j = (i + k) mod length`

不符合题意:需要额外的空间

#### 方法二

~~根据`k`将数组分为两组`[0,k-1]`和`[k,n-1]`~~
根据`k`将数组分为两组`[0,k%length-1]`和`[k%length,n-1]`

- 第一步逆置两组
- 第二步逆置整个数组

> 注:我只考虑了`k < length​`的情况,因此需要将数组分为`[0,k%length-1]`和`[k%length,n-1]`

```Java
class Solution {
    public void rotate(int[] nums, int k) {
        int tmp = 0;
		k = k % nums.length;
        
        for(int i = 0, j = nums.length-k-1; i < j ; i++, j--){
            tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
        }

        for(int i = nums.length-k, j = nums.length-1; i < j ; i++, j--){
            tmp = nums[j];
            nums[j] = nums[i]; 
            nums[i] = tmp;
        }

        for(int i = 0, j = nums.length-1; i < j ; i++, j--){
            tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
        }
    }
}
```

```
java.lang.ArrayIndexOutOfBoundsException: -1
  at line 13, Solution.rotate
  at line 57, __DriverSolution__.__helper__
  at line 87, __Driver__.main
```



有问题

### 参考方法

未能凑出时间仔细分析其他方法,只是浏览一遍