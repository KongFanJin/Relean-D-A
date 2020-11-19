// 1, 2, 4, ...
for (int sz = 1; sz < n; sz += sz)
    for (int i = 0; i + sz < n; i += sz + sz)
        // 对arr[i,...,i+sz-1]和arr[i+sz,...,(i+sz+1)+sz]进行归并
        // min((i+sz+1)+szn-1) 防止(i+sz+1)+sz越界
        __merge(arr, i, i + sz - 1, min((i + sz + 1) + szn - 1));

template <typename T>
int __partition(T arr[], int l, int r) {
    T v = arr[l];

    // arr[l+1...j] < v < arr[j+1...i)
    int j = l;
    for (int i = l + 1; i <= r; i++)
        // arr[i]大于标记点的值v, arr[i]放在原地即可, i++
        // arr[i]小于标记点的值v, arr[i]放在arr[j]的后面arr[j+1]
        if (arr[i] < v) {
            j++;
            swap(arr[j], arr[i]);
        }

    swap(arr[l], arr[j]);

    return j;
}