// 1, 2, 4, ...
for (int sz = 1; sz < n; sz += sz)
    for (int i = 0; i + sz < n; i += sz + sz)
        // 对arr[i,...,i+sz-1]和arr[i+sz,...,(i+sz+1)+sz]进行归并
        // min((i+sz+1)+szn-1) 防止(i+sz+1)+sz越界
        __merge(arr, i, i + sz - 1, min((i+sz+1)+szn-1));