参考

- 恋上数据结构与算法 小码哥
- 算法与数据结构 liuyubobobo

# 思考一个问题

一个基础/常用的问题

- 如何在`n`个整数中搜索一个整数?
- 字典
  - 键值对(`k-v`)

>  涉及添加,删除,搜索操作

- 对于数组
  - 无序数组
    - $O(n)$
  - 有序数组
    - 二分查找法(1946年提出,1962年才正确实现),$O(logn)$
- 对于二叉搜索树
  - 时间复杂度$O(logn)$

二分搜索树比数组更好地提供了查询数据之间关系的问题的工具

- min,max
- floor,ceil
- rank:当前数据的名次`i`
- select:查询第`i`名的元素是什么

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

> 注意搜索区间的开闭,从而是否加1,条件判断是否加等号

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

- 左子树的键值 < 节点的键值 < 右子树的键值​
- 子树也满足BST
  - 递归定义
- 存储的元素要具有可比较性,不允许为`NULL`
  - 对于自定义类型,要指定比较方式

> 二分搜索树不一定是一颗完全二叉树;堆一定是完全二叉树,所以堆可以用数组来表示

## Insert

如何插入一个新节点

- 与根`key`比较
  - 大:右子树
  - 小:左子树
- 递归此过程
  - 为空,直接插入
  - 不为空,"覆盖"

```C++
// Recursion
Node* insertRecursive(Node*& node, Key key, Value value) {
    if (node == nullptr) {  // base
        count++;
        return new Node(key, value);
    }

    if (key == node->key)
        node->value = value;  // update value
    else if (key < node->key)
        node->left = insert(node->left, key, value);
    else
        node->right = insert(node->right, key, value);

    return node;
}
```

```C++
// 用两个指针记录父节点和子节点,迭代匹配,找到后插入父节点
// Iterative function to insert a key into BST.
// Root is passed by reference to the function
Node* insertIterative(Node*& node, Key key, Value value) {
    // start with root node
    Node* curr = root;

    // pointer to store parent node of current node
    Node* parent = nullptr;

    // if tree is empty, create a new node and set root
    if (root == nullptr) {
        count++;
        return root = new Node(key, value);
    }

    // traverse the tree and find parent node of key
    while (curr != nullptr) {
        // update parent node as current node
        parent = curr;

        // if given key is less than the current node, go to left subtree
        // else go to right subtree
        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    // construct a new node and assign to appropriate parent pointer
    if (key == node->key) {
        parent->value = value;
    } else if (key < parent->key) {
        parent->left = new Node(key, value);
    } else {
        parent->right = new Node(key, value);
    }

    return root;
}
```

# Contains/Search

> [04-Binary-Search-Tree-Search](https://github.com/liuyubobobo/Play-with-Algorithms/tree/master/05-Binary-Search-Tree/Course%20Code%20(C%2B%2B)/04-Binary-Search-Tree-Search)
>
> - CLion编译不通过
> - VSCode可以编译

- 递归实现与Insert类似

```C++
bool contain(const Node*& node, Key key) const {
    if (node == nullptr)  // base
        return false;

    if (key == node->key)
        return ture;
    else if (key < node->key)
        contain(node->left, key);
    else
        contain(node->right, key);
}

Value* search(const Node*& node, Key key) const {
    if (node == nullptr) {  // base
        return nullptr;
    }
    if (key == node->key)
        return &(node->value);
    else if (key < node->key)
        return search(node->left, key, value);
    else
        return search(node->right, key, value);
}
```

二分搜索与顺序搜索的比较

```shell
There are totally 431180 words in bible.txt

'god' : 2301
BST , time: 1.019 s.

'god' : 2301
SST , time: 20.864 s.
```

# Traverse

- 前序(先根)遍历:根->左->右
- 中序(中根)遍历:左->根->右
  - 输出结果是从小到大排列(这是由二分搜索树定义决定的性质)
- 后序(后根)遍历:左->右->根

## Recursive

```C++
void preOrder(Node* node) {
    if (node != nullptr) {
        cout << node->key << "\n";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->key << "\n";
        inOrder(node->right);
    }
}

void postOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        inOrder(node->right);
        cout << node->key << "\n";
    }
}
```

