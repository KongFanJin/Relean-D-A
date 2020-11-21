来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/move-zeroes

### Promblem

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
```
Note:
- You must do this in-place without making a copy of the array.
- Minimize the total number of operations.

### Analyse
算法概述
- ~~`i`标记第一个`0`的位置~~
- ~~`j`标记第一个不是`0`的位置~~
- ~~交换`a[i]`和`a[j]`~~
- ~~`i`,`j`移动,直到数组末端~~

### Reference

作者：zhulg
链接：https://leetcode-cn.com/problems/move-zeroes/solution/0-ms-zai-suo-you-java-ti-jiao-zhong-ji-bai-liao--2/

- 遍历数组，无为0的元素移动数组前方，用index下标记录。
- 遍历结束，对index值后的元素统一设为0

```Java
class Solution {
    public void moveZeroes(int[] nums) {
      int index = 0;
      for(int num:nums){
          if(num!=0){
              nums[index]=num;
              index++;
          }
      }
      while(index < nums.length){
          nums[index] = 0;
          index++;
      }
    }
}
```

