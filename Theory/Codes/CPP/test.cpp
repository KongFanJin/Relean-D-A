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

void shiftUp(int k) {
    // data[k / 2] < data[k] 不满足最大堆定义
    // k > 1 越界检查
    while (k > 1 && data[k / 2] < data[k]) {
        swap(data[k / 2], data[k]);
        k /= 2;  // 跳到上一层
    }
}

void shiftDown(int k) {
    // 2*k <= count: 完全二叉树一定有左孩子
    while (2 * k <= count) {
        int j = 2 * k;  // 在此轮循环中,data[k]和data[j]交换位置

        // j + 1 <= count: 判断是否有右孩子
        // data[j] 是 data[2*k]和data[2*k+1]中的最大值
        if (j + 1 <= count && data[j + 1] > data[j]) j++;

        // 父节点大于孩子节点,则不需要交换
        if (data[k] >= data[j]) break;

        swap(data[k], data[j]);

        k = j;
    }
}

// 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
Item extractMax() {
    assert(count > 0);
    Item ret = data[1];

    swap(data[1], data[count]);
    count--;
    shiftDown(1);

    return ret;
}

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

// 通过一个给定数组创建一个最大堆, 时间复杂度为O(n)
MaxHeap(Item arr[], int n) {
    data = new Item[n + 1];
    capacity = n;

    for (int i = 0; i < n; i++) data[i + 1] = arr[i];
    count = n;

    // 从第一个非叶子节点开始shiftDown操作
    for (int i = count / 2; i >= 1; i--) shiftDown(i);
}
