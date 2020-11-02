| 名称           | 时间复杂度最好 | 时间复杂度最坏                  | 时间复杂度平均 | 空间复杂度 | in-place | 稳定性 |
| -------------- | -------------- | ------------------------------- | -------------- | ---------- | -------- | ------ |
| Insertion Sort | $O(n)$         | $O(n^2)$                        | $O(n^2)$       | $O(1)$     | Y        | Y      |
| Shell Sort     | $O(n)$         | $O(n^{\frac{4}{3}})\sim O(n^2)$ | 取决于步长     | $O(1)$     | Y        | N      |
| Bubble Sort    | $O(n)$         | $O(n^2)$                        | $O(n^2)$       | $O(1)$     | Y        | Y      |
| Quick Sort     | $O(nlogn)$     | $O(n^2)$                        | $O(nlogn)$     | $O(logn)$  | Y        | N      |
| Merge Sort     | $O(nlogn)$     | $O(nlogn)$                      | $O(nlogn)$     | $O(n)$     | N        | Y      |
| Selection Sort | $O(n^2)$       | $O(n^2)$                        | $O(n^2)$       | $O(1)$     | Y        | Y      |
| Heap Sort      | $O(nlogn)$     | $O(nlogn)$                      | $O(nlogn)$     | $O(1)$     | Y        | N      |
| Counting Sort  | $O(d*(n+k))$   | $O(d*(n+k))$                    | $O(d*(n+k))$   | $O(n+k)$   | N        | Y      |
| Radix Sort     | $O(n+k)$       | $O(n+k)$                        | $O(n+k)$       | $O(n+m)$   | N        | Y      |
| Bucket Sort    | $O(n+k)$       | $O(n+k)$                        | $O(n+k)$       | $O(n+k)$   | N        | Y      |

- 基于数组排序的结论

- 前7种排序属于比较排序

- Shell Sort是Insertion Sort的改进版