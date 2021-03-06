为什么要学习/了解$O(n^2)$复杂度的排序算法?
- 是其他排序算法的基础
- 易于实现
- 特殊情形下更能会更加有效
- 作为复杂算法的子过程


| 名称           | 时间复杂度-最好 | 时间复杂度-最坏                 | 时间复杂度-平均 | 空间复杂度        | 原地算法 | 稳定性 |                说明                |
| -------------- | --------------- | ------------------------------- | --------------- | ----------------- | -------- | ------ | :--------------------------------: |
| Insertion Sort | $O(n)$          | $O(n^2)$                        | $O(n^2)$        | $O(1)$            | Y        | Y      |                                    |
| Shell Sort     | $O(n)$          | $O(n^{\frac{4}{3}})\sim O(n^2)$ | 取决于步长      | $O(1)$            | Y        | ==N==  | Shell Sort是Insertion Sort的改进版 |
| Bubble Sort    | $O(n)$          | $O(n^2)$                        | $O(n^2)$        | $O(1)$            | Y        | Y      |                                    |
| Quick Sort     | $O(nlogn)$      | $O(n^2)$                        | $O(nlogn)$      | 栈的空间$O(logn)$ | Y        | ==N==  |                                    |
| Selection Sort | $O(n^2)$        | $O(n^2)$                        | $O(n^2)$        | $O(1)$            | Y        | Y      |                                    |
| Heap Sort      | $O(nlogn)$      | $O(nlogn)$                      | $O(nlogn)$      | $O(1)$            | Y        | ==N==  |                                    |
| Merge Sort     | $O(nlogn)$      | $O(nlogn)$                      | $O(nlogn)$      | $O(n)$            | N        | Y      |                                    |

| 名称           | 时间复杂度-最好 | 时间复杂度-最坏                 | 时间复杂度-平均 | 空间复杂度        | 原地算法 | 稳定性 |                说明                |
| -------------- | --------------- | ------------------------------- | --------------- | ----------------- | -------- | ------ | :--------------------------------: |
| Counting Sort  | $O(d*(n+k))$    | $O(d*(n+k))$                    | $O(d*(n+k))$    | $O(n+k)$          | N        | Y      |                                    |
| Radix Sort     | $O(n+k)$        | $O(n+k)$                        | $O(n+k)$        | $O(n+m)$          | N        | Y      |                                    |
| Bucket Sort    | $O(n+k)$        | $O(n+k)$                        | $O(n+k)$        | $O(n+k)$          | N        | Y      |                                    |

- 结论基于数组排序的结论
- 前7种排序属于比较排序


稳定性:
- 稳定:相等的两个元素,在排序前后的相对位置保持不变
- 不稳定:相等的两个元素,在排序前后的相对位置变化
> 例如当对自定义的类型的某个属性排序时,由于不稳定相对位置变化产生
- 冒泡排序是稳定算法,只有左右大小不等时,才会交换位置,若改为"<="就变为不稳定了

原地算法:

- 不依赖额外资源(或依赖少量资源),仅依靠输出来覆盖输入
> 仅对传入数组进行操作,不借助额外空间,$O(1)$
