// __function 表示私有函数

#ifndef INC_03_MERGE_SORT_ADVANCE_MERGESORT_H
#define INC_03_MERGE_SORT_ADVANCE_MERGESORT_H

#include <iostream>

using namespace std;

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r) {
    // length([l:r]) = r - l + 1 
    T aux[r - l + 1];

    // 元素下标不一致 aux[i]对应的是arr[l+i]
    for (int i = l; i <= r; i++) aux[i - l] = arr[i];

    // i指向左半部分的起始索引位置: l
    // j指向右半部分起始索引位置: mid + 1
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {  // i > mid, 则左半部分元素已经全部处理完毕
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {  // j > r,则右半部分元素已经全部处理完毕
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l]) {  // 左半部分所指元素 < 右半部分所指元素
            arr[k] = aux[i - l];
            i++; // 左半边指针移动
        } else {  // 左半部分所指元素 >= 右半部分所指元素
            arr[k] = aux[j - l];
            j++; // 右半边指针移动
        }
    }
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
// 注意边界定义:[),(],[]
template <typename T>
void __mergeSort(T arr[], int l, int r) {
    if (l >= r) return;  // 递归基/递归出口:表示只有一个元素/空

    // int + int > int
    // l + (r-l)/2
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    // 合并子函数
    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}

#endif  // INC_03_MERGE_SORT_ADVANCE_MERGESORT_H
