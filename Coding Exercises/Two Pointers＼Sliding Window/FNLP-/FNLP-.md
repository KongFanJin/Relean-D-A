# 描述

将数组里的负数排在数组的前面，正数排在数组的后面。但不改变原先负数和正数的排列顺序。
- `input: -5，2，-3, 4，-8，-9, 1, 3，-10`
- `output: -5, -3, -8, -9, -10, 2, 4, 1, 3`

# 分析

## 暴力

## 双指针

- 使用`[0,k)`记录负数的部分
  - `k`指向距离`[0,k)`最近正数
- 当`i`遇到负数时,`swap(nums[k], nums[i])`