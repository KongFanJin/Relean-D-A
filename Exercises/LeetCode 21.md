来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists

### 问题描述

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

```
示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

### 分析

链表方便插入和删除,不方便查找

> 由于Java链表和C++链表的区别已忘记,先复习Java实现的链表

算法描述

- `P1`,`P2`分别指向`L1`,`L2`头结点
- 若`L1`,`L2`链表非空,
- 分别比较首节点,取小者留下
  - `L1 > L2`,将`L2`插入`L1`之前
    - `P2`向后移动
  - `L1 < L2`,将`L2`插入`L1`之后
    - `P1`向后移动
