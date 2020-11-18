# Insertion Sort

## 算法描述

通常人们整理桥牌的方法是一张一张的来，将每一张牌插入到其他已经有序的牌中的适当位置 。在计算机的实现中，为了给要插入的元素腾出空间，我们需要将其余所有元素在插入之前都向右移动一位 。 这种算法叫做插入排序

与选择排序一样，当前索引左边的所有元素都是有序的，但它们的最终位置还不确定，为了给更小的元素腾出空间 ，它们可能会被移动 。 但是当索引到达数组的右端时，数组排序就完成了 。
和选择排序不同的是，插入排序所需的时间取决于输入中元素的初始顺序 。 

- 例如，对一个很大且其中的元素已经有序（或接近有序）的数组进行排序将会比对随机顺序 的数组或是逆序数组进行排序要快得多 。

插入排序对于实际应用中常见的某些类型的非随机数组很有效 。 

- 例如，正如刚才所提到的， 想想当你用插入排序对一个有序数组进行排序时会发生什么 。 插入排序能够立 即发现每个元素都已经在合适的位置之上，它的运行时间也是线性的（对于这种数组，选择排序的运行时间是平方级别的 ） 。对于所有主键都相同的数组也会出现相同的情况  

## 实现

```C++
class Solution {
public:
    // InsertionSort
    // increasing order
    vector<int> sortArray(vector<int>& nums){
        // nums[0] 默认已排好序
        // i之前是排序好序的序列,i之后是未排序的序列
        for(auto i = 1; i < nums.size(); i++){
            // 要插入的元素值
			auto v = nums[i];
            // 要插入的元素位置
            auto p = i;
            // 目的:将nums[i]插入nums[i-1],nums[i-2],...,nums[1],num[0]序列中
            // 保证要插入的位置不能小于0
            // 当左侧位置的元素小于要插入的元素值时,需要向左移动,以便继续比较找合适的位置插入
            while(p > 0 && nums[p-1] > v) {
                // 要插入的元素的值已经被v存储,被覆盖了也无所谓,找到新位置重新赋值即可
                nums[p] = nums[p-1];
                // 移动下标
                p = p - 1;
            }
            //经过上面的循环,找到了合适的插入位置
            nums[p] = v;
        }

         return nums;
    }
};
```

> `while`只是向右移动元素找位置,并不是交换元素
>
> - 相当于插入扑克牌时,一直拿着要插入的扑克牌,找到位置后,插入

```C++
class Solution {
public:
    // InsertionSort
    // increasing order
    vector<int> sortArray(vector<int>& nums){
        // nums[0] 默认已排好序
        // i之前是排序好序的序列,i之后是未排序的序列
        for(auto i = 1; i != nums.size(); i++){ 
            // 将nums[i]插入nums[i-1],nums[i-2],...,nums[1],num[0]序列中
            // 通过交换,找num[j-1]<num[j]=nums[i]<num[j+1]的位置j;可能会不止一次的交换
            for(auto j = i; j > 0 && nums[j] < nums[j-1]; j--)
                swap(nums[j],nums[j-1]);
        }

         return nums;
    }
};
```

> 要插入扑克牌,向左交换,在不大于(`nums[j] < nums[j-1]`)要插入扑克牌的位置(`nums[j]`)处插入(`swap(nums[j],nums[j-1])`)

## 算法分析(待补)

- 粗略分析:$O(n^2)$
- 最好情况:

## 改进

我们要考虑的更一般的清况是==部分有序==的数组 。倒置指的是数组中的两个顺序颠倒的元素 。 比如 EXAMPLE 中有 11 对倒置： E-A 、 X-A 、 X-M 、 X-P 、 X-L 、 X-E 、 M-L 、 M-E 、 P-L 、 P-E以及 L-E。 如果数组中倒置的数屈小于数组大小的某个倍数，那么我们说这个数组是部分有序的 。

下面是几种典型的部分有序的数组：

- 数组中每个元素距离它的最终位置都不远；
- 一个有序的大数组接一个小数组；
- 数组中只有几个元素的位置不正确 。

插入排序对这样的数组很有效，而选择排序则不然 。 事实上，当倒置的数量很少时，插入排序很可能比本章中的其他任何算法都要快 。 

要大幅提高插入排序的速度并不难，只需要在内循环中将较大的元素都向右移动而不总是交换两个元素（这样访问数组的次数就能减半）  

```C++
class Solution {
public:
    // InsertionSortX
    // increasing order
    vector<int> sortArray(vector<int>& nums){
        // put smallest element in position to serve as sentinel
        // 将较大的元素向右移动,这样最小的元素就被交换到nums[0]
	    bool exchanges = false;
     	for(auto i = nums.size() - 1; i != 0; i --){
            if(nums[i] < nums[i-1]) {
                swap(nums[i], nums[i-1]);
                // 标记交换过
                exchanges = true;
            }
        }
		
        // 没有交换过,即nums[i]总是大于nums[i-1],序列是递增的
        if(!exchanges) return nums;
        
        // insertion sort with half-exchanges
        // nums[0]是最小元素,nums[0] < nums[1]
        // 从nums[1]与nums[2]开始处理
        for(auto i = 2; i != nums.size(); i++){
            auto j = i;
            auto v = nums[i];
            // 若nums[i] < nums[i-1]
            // 将nums[i-1]覆盖nums[i],即将比nums[i]打的元素向右移一位
		   while(v < nums[j-1]){ 
               nums[j] = [j-1]; 
               j --;
           }
            // 通过循环将比v(nums[i])大的元素通过覆盖num[i]右移
            // 相当在比v(nums[i])小的元素后后面"空"出一位
           nums[j] = v;
        }
        
    	return nums;
    }
};
```

总的来说，插入排序对千部分有序的数组十分高效，也很适合小规模数组 。 这很重要，因为这些类型的数组在实际应用中经常出现，而且它们也是高级排序算法的中间过程 。 我们会在学习高级排序算法时再次接触到插入排序 。   

> leetcode超时,时间复杂度大致还是$O(n^2)$,改进的没有意义?
>
> - 可能由于测试数据集都是随机序列
