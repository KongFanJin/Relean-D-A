参考
- Algorithm 4th 2-4-1

> 暂时没有按照Algorithm 4th的优先队列来实现,内容过多,有时间再复习

- [花花酱 LeetCode 912. Sort an Array](https://zxi.mytechroad.com/blog/algorithms/array/leetcode-912-sort-an-array/)

前置知识点

- 二叉树

# HeapSort

## 算法描述

执行流程

- 对序列原地建堆(`heapify`)
  - $O(n)$
- 重复执行以下操作,直到堆的元素数量为`1`
  - 交换堆顶元素与尾元素
  - 堆的元素数量减`1`
  - 堆`0`位置进行`1`次`siftDown`操作

## 若对一个任意的数组原地建堆