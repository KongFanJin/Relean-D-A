参考

- 恋上数据结构与算法 小码哥
- 算法与数据结构 liuyubobobo

# 思考一个问题

一个基础/常用的问题

- 如何在`n`个整数中搜索一个整数?
- 类似于查字典(`k-v`)

>  涉及添加,删除,搜索操作

- 对于数组
  - 无序数组
  - 有序数组
    - 二分查找法(1946年提出,1962年才正确实现)
  - 时间复杂度
    - 最好:$O(logn)$
    - 最坏:$O(n)$
- 对于二叉搜索树
  - 时间复杂度$O(logn)$

# Binary Search(BS)

详细见[二分查找细节详解，顺便赋诗一首](https://leetcode-cn.com/problems/binary-search/solution/er-fen-cha-zhao-xiang-jie-by-labuladong/)

```C++
template<typename T>
vector<T> binarySearch(vector<T> &arr, T target);

template<typename T>
bool binarySearch(vector<T> arr, T target){
    T l = 0,r = arr.size() - 1; // arr[l:r]
    while(l <= r){ // 注意边界的判断
        // T mid = (l+r)/2; // 可能产生int的溢出
        T mid = l + (r-l)/2;
        if(arr[mid] == mid)
            return true;
        if(arr[mid] < mid){ 
            r = mid - 1; // 注意边界的判断
        }else{
            l = mid + 1;
    }
     
    return false;
}
```

```C++
template<typename T>
vector<T> binarySearch(vector<T> &arr, T target);

template<typename T>
bool binarySearch(vector<T> arr, T target){
    T l = 0,r = arr.size(); // arr[l:r)
    while(l < r){ // 注意边界的判断
        // T mid = (l+r)/2; // 可能产生int的溢出
        T mid = l + (r-l)/2;
        if(arr[mid] == mid)
            return true;
        if(arr[mid] < mid){ 
            r = mid + 1; // 注意边界的判断
        }else{
            l = mid;
    }
     
    return false;
}
```

> 注意搜索区间的开闭

递归实现

```C++

int recurse(vector<int>& nums, int low, int high, int target) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) 
            return mid;
        else if (target > nums[mid]) 
            return recurse(nums, mid + 1, high, target);
        else 
            return recurse(nums, low, mid - 1, target);
    }
    else return -1;
}

int search(vector<int>& nums, int target) {
    return recurse(nums, 0, nums.size() - 1, target);
}
```

> 理解递归思维,寻找子问题

## 关于`floor`和`ceil`(或`lowerbound`和`higherbound`)

查找元素

- `floor`:第一次出现的位置
- `ceil`:最后出现的位置

[详见](https://github.com/liuyubobobo/Play-with-Algorithms/tree/master/05-Binary-Search-Tree/Course%20Code%20(C%2B%2B)/Optional-02-Floor-and-Ceil-in-Binary-Search)

# Binary Search Tree(BST)

> 二叉搜索树,二叉排序树二叉查找树

特点

- $左子树 < 节点 < 右子树$
- 递归定义,子树也满足BST
- 存储的元素要具有可比较性,不允许为`NULL`
  - 对于自定义类型,要指定比较方式

# 接口设计

```C++
int size();
bool isEmpty();
void clear();
void add(E element);
void remove(E element);
bool contains(E elements);
```

# 实现
