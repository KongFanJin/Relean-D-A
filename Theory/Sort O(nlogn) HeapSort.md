参考
- Algorithm 4th 2-4-1
> 暂时没有按照Algorithm 4th的优先队列来实现,内容过多,有时间再复习

- [花花酱 LeetCode 912. Sort an Array](https://zxi.mytechroad.com/blog/algorithms/array/leetcode-912-sort-an-array/)
- 慕课网 liuyubobobo

前置知识点
- 二叉树

# 优先队列

普通队列
- 先进先出,后进后出

优先队列
- 出队顺序和入队顺序无关,和优先级相关
  - 动态处理
- 应用
  - 人工智能

问题:在`N`个元素中选出前`M`个元素
- 排序:$O(NlogN)$
- 优先队列:$O(NlogM)$



优先队列主要操作
- 入队, 出队
- 使用数组($O(1)$,$O(n)$),顺序数组($O(n)$,$O(1)$)或堆实现优先队列($O(logn)$,$O(logn))$)

# Heap

## 二叉堆 Binary Heap

二叉堆

- 节点均不大于其父节点
- 是完全二叉树

<img src="images/Sort/Heap Sort/01.png" alt="01" style="zoom:50%;" />

最大堆:

- 树顶元素最大
- 节点均不大于其父节点
- 层数高的节点不一定大于低层的节点

最小堆

- 树顶元素最小
- 节点均不小于其父节点

## 用数组存储二叉堆

<img src="images/Sort/Heap Sort/02.png" alt="02" style="zoom:50%;" />

> 根节点从0标记和从1标记有所不同

因为二叉堆是完全二叉树,对二叉堆的节点`i`进行编号,满足以下性质

- `i`的左孩子标记:`leftChild(i) = 2i`
- `i`的右孩子标记:`rightChild(i) = 2i+1`
- `i`的父节点标记:`parent(i) = i/2`
  - 向下取整
<img src="images/Sort/Heap Sort/03.png" alt="03" style="zoom:50%;" />

## Shift Up, 插入元素

<img src="images/Sort/Heap Sort/04.png" alt="04" style="zoom:50%;" />
- 添加`52`
<img src="images/Sort/Heap Sort/05.png" alt="05" style="zoom:50%;" />
- 不满足最大堆定义,需要调整
<img src="images/Sort/Heap Sort/06.png" alt="06" style="zoom:50%;" />
<img src="images/Sort/Heap Sort/07.png" alt="07" style="zoom:50%;" />
<img src="images/Sort/Heap Sort/08.png" alt="08" style="zoom:50%;" />

```C++
void shiftUp(int k) {
    // data[k / 2] < data[k] 不满足最大堆定义
    // k > 1 越界检查
    while (k > 1 && data[k / 2] < data[k]) {
        swap(data[k / 2], data[k]);
        k /= 2;  // 跳到上一层
    }
}
```

## Shift Down, 删除元素 [Todo]

- 只能删除根节点/优先级最大的元素
<img src="images/Sort/Heap Sort/09.png" alt="09" style="zoom:50%;" />
- 然后将堆的最后的元素放在根节点上
<img src="images/Sort/Heap Sort/10.png" alt="10" style="zoom:50%;" />
<img src="images/Sort/Heap Sort/11.png" alt="11" style="zoom:50%;" />
-  调整堆,使之满足最大对定义
	- 与较大的孩子交换位置
<img src="images/Sort/Heap Sort/12.png" alt="12" style="zoom:50%;" />
<img src="images/Sort/Heap Sort/13.png" alt="13" style="zoom:50%;" />

```C++
void shiftDown(int k) {
    /*
     * 完全二叉树的性质:
     *  2k <= count, k有左孩子;
     *  2k > count, k没有左孩子
     *  2k + 1 <= count, k有右孩子
     *  2k + 1 > count, k没有右孩子
     *  注:简单证明可以画图
     */
    // 在此轮循环中,data[k]和data[j]交换位置
    while (2 * k <= count) {
        // 默认选择左孩子
        int j = 2 * k;

        // data[j] 是 data[2*k]和data[2*k+1]中的最大值
        // j + 1 <= count: 判断是否有右孩子
        // data[j + 1] > data[j]: 右孩子大于左孩子
        if (j + 1 <= count && data[j + 1] > data[j]) j++;

        // 父节点大于孩子节点,则不需要交换
        if (data[k] >= data[j]) break;

        swap(data[k], data[j]);

        k = j;
    }
}
```

# 堆排序 Heap Sort

## 建堆 Heapify

将一个数组构成一个完全二叉树
<img src="images/Sort/Heap Sort/14.png" alt="14" style="zoom:50%;" />
- 叶子节点可以看做只有一个节点的堆
<img src="images/Sort/Heap Sort/15.png" alt="15" style="zoom:50%;" />
- 完全二叉树第一个非叶子节点的序号是`n/2`
- 进行`shiftDown(n/2)`操作
<img src="images/Sort/Heap Sort/16.png" alt="16" style="zoom:50%;" />
- 进行`shiftDown(n/2-1)`操作
<img src="images/Sort/Heap Sort/17.png" alt="17" style="zoom:50%;" />
- 进行`shiftDown(n/2-2)`操作
<img src="images/Sort/Heap Sort/18.png" alt="18" style="zoom:50%;" />
- 进行`shiftDown(n/2-3)`操作
<img src="images/Sort/Heap Sort/19.png" alt="19" style="zoom:50%;" />
<img src="images/Sort/Heap Sort/20.png" alt="20" style="zoom:50%;" />
- 进行`shiftDown(root)`操作
<img src="images/Sort/Heap Sort/21.png" alt="21" style="zoom:50%;" />
<img src="images/Sort/Heap Sort/22.png" alt="22" style="zoom:50%;" />
<img src="images/Sort/Heap Sort/23.png" alt="23" style="zoom:50%;" />

```C++
// 通过一个给定数组创建一个最大堆, 时间复杂度为O(n)
MaxHeap(Item arr[], int n) {
    data = new Item[n + 1];
    capacity = n;

    for (int i = 0; i < n; i++) data[i + 1] = arr[i];
    count = n;

    // 从第一个非叶子节点开始shiftDown操作
    for (int i = count / 2; i >= 1; i--) shiftDown(i);
}
```

## 原地堆排序
- `v`数组第一个元素根是最大值
<img src="images/Sort/Heap Sort/24.png" alt="24" style="zoom:50%;" />
- `v`与数组未元素`w`交换
<img src="images/Sort/Heap Sort/25.png" alt="25" style="zoom:50%;" />
- `shiftDown(w)`重建堆
<img src="images/Sort/Heap Sort/26.png" alt="26" style="zoom:50%;" />
- `v`与数组未元素`w`交换
<img src="images/Sort/Heap Sort/27.png" alt="27" style="zoom:50%;" />



根的标号要从`0`开始
<img src="images/Sort/Heap Sort/28.png" alt="28" style="zoom:50%;" />
<img src="images/Sort/Heap Sort/29.png" alt="29" style="zoom: 50%;" />
> 图中的最后一个非叶子节点的索引是`((count-1)-1)/2 = (count-2)/2`

```C++
// 不使用一个额外的最大堆, 直接在原数组上进行原地的堆排序
template <typename T>
void heapSort(T arr[], int n) {
    // 注意，此时我们的堆是从0开始索引的
    // 从(最后一个元素的索引-1)/2开始
    // 最后一个元素的索引 = n-1
    for (int i = (n - 1 - 1) / 2; i >= 0; i--) __shiftDown(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        __shiftDown2(arr, i, 0);
    }
}

template <typename T>
void __shiftDown(T arr[], int n, int k) {
    // 注意，此时我们的堆是从0开始索引的
    while (2 * k + 1 < n) {
        int j = 2 * k + 1;
        if (j + 1 < n && arr[j + 1] > arr[j]) j += 1;

        if (arr[k] >= arr[j]) break;

        swap(arr[k], arr[j]);
        
        k = j;
    }
}

```

# 索引堆 Index Heap [Todo]

# 和堆相关的其他问题

- 使用堆来实现优先队列
- 多路归并排序
- d叉堆
- 最大/最小队列
- 二项堆
- 斐波那契堆