# 连接问题 (Connectivity Problem)

- 图中如何确定两点之间是否相连?
<img src="images/Union Find/connectivity.png" alt="connectivity" style="zoom:50%;" />



应用

- 确定网络中节点间的连接状态
  - 例如: 用户之间形成的网络
- 数学中的集合类实现



连接问题和路径问题

- 连接问题比路径问题要回答的问题少,不需要解决额外的问题
- 类似的问题
  - 顺序查找与二分查找
    - 顺序查找记录了Rank等信息
  - 堆排序方便找到最大值和最小值

# 并查集 (Union Find)

对于一组数据,主要支持两个动作

- `union(p,q)`:将`p,q`合并/连接
  - ==是合并两个点,还是合并两个点所属的集合?==
- `find(p)`:查看`p`所在组
- `isConnected(p,q)`:查看`p,q`是否连接

# 实现方式1

- 基本的数据表示
  - 示例1
    <img src="images/Union Find/数据表示-1.png" alt="数据表示-1" style="zoom:50%;" />
  - 示例2
    <img src="images/Union Find/数据表示-2.png" alt="数据表示-2" style="zoom:50%;" />

# 实现方式2

- 将每个元素,看做是一个节点
  - 区别于树的节点,该节点指向其父亲
  - 根节点指向自己
- 合并操作
  - 指向合并后的父亲节点
  - 或者将另一个根节点指向令一个根节点来完成合并
<img src="images/Union Find/数据表示-3.png" alt="数据表示-3" style="zoom:50%;" />
<img src="images/Union Find/数据表示-4.png" alt="数据表示-4" style="zoom:50%;" />
<img src="images/Union Find/数据表示-5.png" alt="数据表示-5" style="zoom:50%;" />

**示例**
<img src="images/Union Find/数据表示-6.png" alt="数据表示-6" style="zoom:50%;" />

- `union(3,4)`
<img src="images/Union Find/union 4,3.png" alt="union 4,3" style="zoom:33%;" />
- `union(3,8)`
<img src="images/Union Find/union 3,8.png" alt="union 3,8" style="zoom: 33%;" />
- `union(6,5)`
<img src="images/Union Find/union 6,5.png" alt="union 6,5" style="zoom:33%;" />
- `union(9,4)`
  <img src="images/Union Find/union 4,9.png" alt="union 4,9" style="zoom:33%;" />
  - `9`连接到`4`上也可以,但是树变高了,效率变低了,所以`union`时连接的是两个元素的根
- `union(2,1)`
<img src="images/Union Find/union 2,1.png" alt="union 2,1" style="zoom:33%;" />
- `union(5,0)`
<img src="images/Union Find/union 5,0.png" alt="union 2,1" style="zoom:33%;" />
- `union(7,2)`
<img src="images/Union Find/union 7,2.png" alt="union 2,1" style="zoom:33%;" />
- `union(6,2)`
<img src="images/Union Find/union 6,2.png" alt="union 2,1" style="zoom:33%;" />

# 实现方式2的优化:基于`size`

- 合并时,可能将高树合并到矮树上
  <img src="images/Union Find/union 4,9 optimum-1.png" alt="union 4,9 optimum" style="zoom:33%;" />
  <img src="images/Union Find/union 4,9 optimum.png" alt="union 4,9 optimum" style="zoom:33%;" />
  - 解决方法:记录集合的元素数,将集合元素少的集合合并到集合元素多的集合中

# 实现方式2的优化:基于`rank`

- 合并时,根据树高(层)来合并
<img src="images/Union Find/union-rank-01.png" alt="union-rank-01" style="zoom:33%;" />
<img src="images/Union Find/union-rank-02.png" alt="union-rank-02" style="zoom:33%;" />

# 路径压缩

- 减少层数
<img src="images/Union Find/Path Compression 01.png" alt="Path Compression 01" style="zoom:33%;" />
<img src="images/Union Find/Path Compression 02.png" alt="Path Compression 02" style="zoom:33%;" />
<img src="images/Union Find/Path Compression 03.png" alt="Path Compression 03" style="zoom:33%;" />
<img src="images/Union Find/Path Compression 04.png" alt="Path Compression 04" style="zoom:33%;" />

- 最优情形:只有2层
	- 即,`find(parent(i)) = parent(i)` 
<img src="images/Union Find/Path Compression 05.png" alt="Path Compression 05" style="zoom:33%;" />

