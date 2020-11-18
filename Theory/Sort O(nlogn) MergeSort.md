参考

- Algorithm 4th 2-2
- [花花酱 LeetCode 912. Sort an Array](https://zxi.mytechroad.com/blog/algorithms/array/leetcode-912-sort-an-array/)
- [慕课网  liuyubobobo](https://coding.imooc.com/learn/list/71.html)
- [陈小玉](https://ke.qq.com/course/480225)

# MergeSort

归并:
- 将两个有序的数组归并成一个更大的有序数组 

归并排序:
-  要将一个数组排序，可以先（递归地）将它分成两半分别排序，然后将结果归并起来 。 

优点:
- 它能够保证将任意长度为$N$的数组排序所需时间和$NlogN$成正比；

缺点:
- 它所需的额外空间和$N$成正比 

## Top-down mergesort (递归向下)

<img src="images/Sort/Merge Sort/01.png" alt="01" style="zoom:50%;" />
- 归并第3层(从0层开始)
<img src="images/Sort/Merge Sort/02.png" alt="02" style="zoom:50%;" />
- 归并第2层
<img src="images/Sort/Merge Sort/03.png" alt="03" style="zoom:50%;" />
- 归并第1层,完成归并排序
<img src="images/Sort/Merge Sort/04.png" alt="04" style="zoom:50%;" />



层数 : $O(log_n)$, 归并操作:$O(n)$



==如何进行归并操作==:将两个有序序列合并成一个有序序列

- 借助临时/辅助空间
- 不借助临时/辅助空间

### 借助辅助空间

将两个有序序列合并成一个有序序列
- 通过三个"指针"
- 两个指针指向要归并的序列,第三个指针指向辅助空间
<img src="images/Sort/Merge Sort/05.png" alt="05" style="zoom:50%;" />
<img src="images/Sort/Merge Sort/06.png" alt="05" style="zoom:50%;" />
<img src="images/Sort/Merge Sort/07.png" alt="05" style="zoom:50%;" />
- `[l, r]`
<img src="images/Sort/Merge Sort/08.png" alt="05" style="zoom:50%;" />

### 不借助辅助空间

不借助额外存储空间,原地归并

> 待补

基于原地归并的抽象实现了另一种递归归并，这也是应用高效算法设计中分治思想的最典型 的一个例子 。 这段递归代码是归纳证明算法能够正确地将数组排序的基础 ：如果它能将两个子数组排序，它就能够通过归并两个子数组来将整个数组排序 。  

```C++
//Top-down mergesort  
class Solution {
public:
	  vector<int> sortArray(vector<int>& nums){
          
      }
};
```



## Down-top mergesort (迭代向上)

<img src="images/Sort/Merge Sort/09.png" alt="09" style="zoom:50%;" />

- 第1轮,2个元素一组
<img src="images/Sort/Merge Sort/10.png" alt="10" style="zoom:50%;" />
<img src="images/Sort/Merge Sort/11.png" alt="11" style="zoom:50%;" />
-  第2轮,4个元素一组
<img src="images/Sort/Merge Sort/12.png" alt="12" style="zoom:50%;" />
<img src="images/Sort/Merge Sort/13.png" alt="13" style="zoom:50%;" />
-  第8轮,8个元素一组
<img src="images/Sort/Merge Sort/14.png" alt="14" style="zoom:50%;" />

```C++
// 1, 2, 4, ...
for (int sz = 1; sz < n; sz += sz)
    for (int i = 0; i + sz < n; i += sz + sz)
        // 对arr[i,...,i+sz-1]和arr[i+sz,...,(i+sz+1)+sz]进行归并
        // min((i+sz+1)+szn-1) 防止(i+sz+1)+sz越界
        __merge(arr, i, i + sz - 1, min((i+sz+1)+szn-1));
```

- 没有使用数组的特性,因此可以对链表进行归并排序

# 花花酱的实现

- 使用C++的新特性Lambda表达式,[简介](https://imzlp.me/posts/2441/)

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

