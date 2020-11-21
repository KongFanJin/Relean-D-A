源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array

### 问题描述

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:
- 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
- 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:

```
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
```



### 分析

对比21题合并两个有序链表



#### 方法一

~~算法描述:~~

- ~~相当于直接插入排序~~

时间复杂度`O(mn)`

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int i = 0; i < n; i++){
            int location = 0;
            // 查找位置
            for(int j = 0; j < m + i; j++)
                if(nums1[j] > nums2[i]){
                    location = j;
                    break;
                }
            // 空出位置
            for(int k = n + i; k > location-1; k-- )
                nums1[k] = nums1[k-1];
            // 插入
            nums1[location] = nums2[i];
        }
}
```
```
java.lang.ArrayIndexOutOfBoundsException: -1
  at line 11, Solution.merge
  at line 57, __DriverSolution__.__helper__
  at line 91, __Driver__.main
```

脑袋发蒙,清醒了再写

#### 方法二

[参考](https://leetcode-cn.com/problems/merge-sorted-array/solution/java-ti-jie-88he-bing-liang-ge-you-xu-shu-zu-by-13)

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int pos = m + n - 1;
        
        while(n > 0){
            if(m > 0 && nums1[m-1] > nums2[n-1]){
                nums1[pos] = nums1[m-1];
                pos--;
                m--;
            }else{
                nums1[pos] = nums2[n-1];
                pos--;
                n--;
            }
        }   
    }
}
```

