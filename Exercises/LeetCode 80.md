来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii

### 问题描述

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

**示例 1:**

```
给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
```

**示例 2:**

```
给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
```

**说明:**

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

```
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

### 分析

- 数组有序
- 空间复杂度为$O(1)$,即不能借助其他辅助空间
- 连续相等的元素最多两个

#### 我的思路

- ~~元素个数小于三个,无法满足重复度大于2~~
  - ~~退出函数~~

- ~~`flag`:记录元素的相等次数~~
  - ~~当下一个元素与当前元素相等时~~
    - ~~`flag++`~~
  - ~~当下一个元素与当前元素不等时~~
    - ~~`flag = 1`重置为`1`~~
  - ~~当大于`2`时~~
    - ~~用后面的元素覆盖前面的元素~~
  - ~~循环到最后一个元素~~
- ~~找下一个连续重复度大于`2`的元素~~
- ~~直到没有重复度大于`2`的元素为止~~

元素重复度为`3`,就是`nums[i] == nums[i+2]`为真,则用后面的元素覆盖到`i+2`为止,然后找下一个重复度为`3`的元素

### 作答

```Java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length < 3)
            return nums.length;

        int dup = 0;
        for(int i = 0 ;i < nums.length - 2; i++){
            if(nums[i] == nums[i+2])
                dup = 1;
            // 用后面的元素覆盖第3个重复元素
            for(int j = i + 2; dup == 1 && j < nums.length - 1; j ++)
                nums[j] = nums[j+1];
            dup = 0;
        }
            
        return nums.length - 1;
    }
}
```

时间复杂度应该小于$O(n^2)$,除非每一个元素都重复度大于`3`

### 参考方法 

未能凑出时间仔细分析其他方法,只是浏览一遍

**方法一**

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        for(int n:nums)
            if(i < 2 || n > nums[i-2])
                nums[i++] = n;

        return i;
    }
}
```

**方法二**

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length < 3)
            return nums.length;
        
        int curPos = 1;
        for(int i = 2; i < nums.length; i++)
            if(nums[i] != nums[curPos-1])
                nums[++curPos] = nums[i];
        
        return curPos+1;
    }
}
```

