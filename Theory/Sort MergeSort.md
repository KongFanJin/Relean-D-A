参考

- Algorithm 4th 2-2
- [花花酱 LeetCode 912. Sort an Array](https://zxi.mytechroad.com/blog/algorithms/array/leetcode-912-sort-an-array/)

# MergeSort

归并:将两个有序的数组归并成一个更大的有序数组  
归并排序:要将一个数组排序，可以先（递归地）将它分成两半分别排序，然后将结果归并起来 。  

- 优点:它能够保证将任意长度为$N$的数组排序所需时间和$NlogN$成正比；
- 缺点:它所需的额外空间和$N$成正比  

## Abstract in-place merge

不借助额外存储空间,原地归并

> 待补

## Top-down mergesort

基于原地归并的抽象实现了另一种递归归并，这也是应用高效算法设计中分治思想的最典型 的一个例子 。 这段递归代码是归纳证明算法能够正确地将数组排序的基础 ：如果它能将两个子数组排序，它就能够通过归并两个子数组来将整个数组排序 。  

```C++
//Top-down mergesort  
class Solution {
public:
	  vector<int> sortArray(vector<int>& nums){
          
      }
};
```



## 花花酱

```C++
// Author: Huahua
class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    vector<int> t(nums.size());
    function<void(int, int)> mergeSort = [&](int l, int r) {
      if (l + 1 >= r) return;
      int m = l + (r - l) / 2;
      mergeSort(l, m);
      mergeSort(m, r);
      int i1 = l;
      int i2 = m;
      int index = 0;
      while (i1 < m || i2 < r)
        if (i2 == r || (i1 < m && nums[i1] < nums[i2]))
          t[index++] = nums[i1++];
        else
          t[index++] = nums[i2++];      
      std::copy(begin(t), begin(t) + index, begin(nums) + l);
    };
    
    mergeSort(0, nums.size());
    return nums;
  }
};
```

