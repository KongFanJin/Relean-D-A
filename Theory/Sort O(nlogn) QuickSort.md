# Quick Sort

- 需要选择数组中的一个元素为基点,然后将该元素放置在排好序后应该在的位置上
<img src="images/Sort/Quick Sort/01.png" alt="01" style="zoom:50%;" />

## Partition

一般使用序列的第一个元素`v`为分界的标志点,向右遍历未访问的元素,从而将元素分类为大于`v`的元素和小于`v`的元素,需要记录边界

<img src="images/Sort/Quick Sort/02.png" alt="02" style="zoom:50%;" />
- `e > v`,`e`放在`>v`部分的后面
<img src="images/Sort/Quick Sort/03.png" alt="03" style="zoom:50%;" />
- `e < v`,`e`放在`j`的后面
<img src="images/Sort/Quick Sort/04.png" alt="04" style="zoom:50%;" />
-  `j++`,`i++`
<img src="images/Sort/Quick Sort/05.png" alt="05" style="zoom:50%;" />
- 直到遍历整个序列,然后将`v<->j`
<img src="images/Sort/Quick Sort/06.png" alt="06" style="zoom:50%;" />
<img src="images/Sort/Quick Sort/07.png" alt="07" style="zoom:50%;" />

```C++
// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] < arr[p+1...r]
template <typename T>
int __partition(T arr[], int l, int r) {
    T v = arr[l];

    // arr[l+1...j] < v < arr[j+1...i)
    int j = l;
    for (int i = l + 1; i <= r; i++)
        // arr[i]大于标记点的值v, arr[i]放在原地即可, i++
        // arr[i]小于标记点的值v, arr[i]放在arr[j]的后面arr[j+1]位置
        if (arr[i] < v) {
            j++;
            swap(arr[j], arr[i]);
        }

    swap(arr[l], arr[j]);

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r) return;

    int p = __partition(arr, l, r);  // 关键部分
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}
```

# 随机化快速排序 [Todo]

# 双路快速排序 [Todo]

# 三路快速排序 [Todo]

# 衍生问题 [Todo]

- 思考前人是如何设计/发明的过程
- 快速排序和归并排序属于分治算法
- 归并排序关键是"合"; 快速排序关键是"分"

## 逆序对

- 暴力解法:$O(n^2)$
- 归并排序的思路:$O(nlogn)$

## 取出数组中第`n`大的元素

- 弱化问题:取出数组中的最大值最小值
- 用快速排序的思路$O(n)$

