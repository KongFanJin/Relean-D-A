参考

- Algorithms [Robert Sedgewick Kevin Wayne] 2-1-2
  - https://algs4.cs.princeton.edu/21elementary/Selection.java.html
- https://leetcode-cn.com/problems/sort-an-array/

# SelectionSort

## 算法描述

首先，找到数组中最小的那个元素，其次，将它和数组的第一个元素交换位置（如果第一个元素就是最小元素那么它就和自己交换） 。 再次，在剩下的元素中找到最小的元素 ，将它与数组的第二个元素交换位置 。 如此往复，直到将整个数组排序 。  

选择排序的内循环只是在比较当前元素与目前已知的最小元素（以及将当前索引加 1 和检查是否代码越界），这已经简单到了极点 。 交换元素的代码写在内循环之外，每次交换都能排定一个元素，因此交换的总次数是 N。 所以算法的时间效率取决于比较的次数   

特点

- 运行时间和输入无关 。 
  为了找出最小的元素而扫描一遍数组并不能为下一遍扫描提供什么信息 。这种性质在某些情况下是缺点，因为使用选择排序的人可能会惊讶地发现， 一个已经有序的数组或是主键全部相等的数组和一个元素随机排列的数组所用的排序时间竟然一样长 ！ 

- 数据移动是最少的 。
  每次交换都会改变两个数组元素的值，因此选择排序用了 N 次交换—一交换次数和数组的大小是线性关系 。 我们将研究的其他任何算法都不具备这个特征（大部分的增长数量级都是线性对数或是平方级别） 。

## 实现

```C++
// Selection Sort
vector<int> sortArray(vector<int>& nums){
    for(auto i = 0; i != nums.size(); i++){ // 选出位置i
        int min = i;
        for(auto j = i + 1; j != nums.size(); j++){ // 选出i之后的最小的元素
	    	if(nums[j] < nums[min]) min = j;
        }
        
        swap(nums[i], nums[min]); // 交换位置,交换后nums[i]就是第i小的元素
    }
    
    return nums;
}
```

```C++
// Selection Sort
vector<int> sortArray(vector<int>& nums){
	for(auto end = nums.size() - 1; end != 0; end--){
        int max = end;
        for(auto begin = 0; begin < end; begin++)
            if(nums[begin] < nums[begin+1])
            	max = begin;
        
        swap(nums[end],swap[max]);
    }
    
    return nums;
}
```



## 算法分析

- $\sum_{i=0}^n\sum_{j=i+1}^n\cdot 1 = \sum_{i=0}^n(n-(i+1))$
- 粗略分析:二重循环$O(n^2)$

