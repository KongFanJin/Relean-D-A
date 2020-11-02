参考
- [排序算法](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)
- 恋上数据结构第二季

# BubbleSort

## 算法描述

冒泡排序（英语：Bubble Sort）又称为泡式排序，是一种简单的排序算法。
它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。

这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。

冒泡排序对$n$个项目需要$O(n^2)$的比较次数，且可以原地排序。尽管这个算法是最简单了解和实现的排序算法之一，但它对于包含大量的元素的数列排序是很没有效率的。

冒泡排序是与插入排序拥有相等的运行时间，但是两种算法在需要的交换次数却很大地不同。
- 在最坏的情况，冒泡排序需要$O(n^2)$次交换，而插入排序只要最多$O(n)$交换。
- 冒泡排序的实现（类似下面）通常会对已经排序好的数列拙劣地运行（$O(n^2)$），而插入排序在这个例子只需要$O(n)$个运算。

因此很多现代的算法教科书避免使用冒泡排序，而用插入排序取代之。

冒泡排序如果能在内部循环第一次运行时，使用一个旗标来表示有无需要交换的可能，也可以把最优情况下的复杂度降低到$O(n)$。在这个情况，已经排序好的数列就无交换的需要。若在每次走访数列时，把走访顺序反过来，也可以稍微地改进效率。有时候称为鸡尾酒排序，因为算法会从数列的一端到另一端之间穿梭往返。

冒泡排序算法的运作如下：

- 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
- 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
- 针对所有的元素重复以上的步骤，除了最后一个。
- 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

由于它的简洁，冒泡排序通常被用来对于程序设计入门的学生介绍算法的概念。

## 实现
先考虑内层循环,然后写外层循环
```C++
// 将最大元素排到nums[n-1]
// 然后将次大元素排到nums[n-2]
// ...
// 需要重复直到nums[1]为最小元素无需移动
for(auto begin = 0; begin < nums.size(); begin++)
    	swap(nums[j],nums[j+1]);
```
```C++
// Bubble Sort
// increasing order
class Solution1 {
public:
    vector<int> sortArray(vector<int>& nums){
        for(auto i = nums.size() - 1; i != 0; i --)
            for(auto j = 0; j != i; j++)
                if(nums[j] > nums[j+1]) 
                    swap(nums[j],nums[j+1]);
        
        return nums;
    }
};

// Bubble Sort
// increasing order
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums){
        // 最后一趟扫描元素就一个而且最小,不用比较,故需要n-1趟
        for(auto i = 0; i != nums.size() - 1; i ++)
            // 比较nums[j]和nums[j+1],大者向右交换(移动)
            // 每趟扫描将最大元素交换到a[(n-1)-i]的位置
            // 若比较nums[j]与nums[j-1],注意 1 <= j <= nums.size()- i
            for(auto j = 0; j != (nums.size() - 1) - i; j++)
                if(nums[j] > nums[j+1]) 
                    swap(nums[j],nums[j+1]);
        
        return nums;
    }
};
```
```C++
// Bubble SortX1
// Add Flag
// 数组元素部分有序时
class Solution {
public:
    vector<int> sortArray(vector<int>& nums){
        // 发生交换设为true,未发生交换说明是不递减序列,设为false无需继续比较,提前结束内部循环
        bool flag = false;
        for(auto i = 0; !flag && i != nums.size() - 1; i ++){
            flag = true; 
            for(auto j = 0; j != (nums.size() - 1) - i; j++)
                if(nums[j] > nums[j+1]) {
                    swap(nums[j],nums[j+1]);
                    flag = false;
                }
        }

        return nums;
    }
};
```

```C++
// Bubble SortX2
// Add Flag
// 数组的尾部元素有序时
// 记录最后一次的交换的元素的位置,减少比较次数
// 恋上数据结构第二季

// Bubble Sort
// increasing order
class Solution1 {
public:
    vector<int> sortArray(vector<int>& nums){
        for(auto i = nums.size() - 1; i != 0; i --){
            int index = 0;
            for(auto j = 0; j != i; j++)
                if(nums[j] > nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    index = j;
                }
           i =  index;        
        }

        
        return nums;
    }
};

class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums){
        auto index = 1;
        for(auto i = 0; i != nums.size() - 1; i ++){
            for(auto j = 0; j != (nums.size() - 1) - i; j++)
                if(nums[j] > nums[j+1]){
                    swap(nums[j],nums[j+1]);   
                    index = j + 1; // 记录本趟最后交换元素的位置
                }
            // j != (nums.size() - 1) - i
            // index = (nums.size() - 1) - i => i = (nums.size() - 1)-index
            i = (nums.size() - 1) - index;
        }
        return nums;
    }
};

```



# Cocktail Sort

**鸡尾酒排序**，也就是**定向冒泡排序**，**鸡尾酒搅拌排序**，**搅拌排序**（也可以视作[选择排序](SelectionSort.md)的一种变形），**涟漪排序**，**来回排序**或**快乐小时排序**，是[冒泡排序](#BubbleSort)的一种变形。此算法与[冒泡排序](#BubbleSort)的不同处在于排序时是以双向在序列中进行排序。

> 待补