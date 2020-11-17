# 最短路径问题

- 从一个节点到另外一个节点的最短路径

应用

- 路径规划
- 工作任务规划



<img src="images/Graph SP/Shortest Path.png" alt="Shortest Path" style="zoom:50%;" />

图的广度优先遍历可用于求最短路径
<img src="images/Graph SP/Shortest Path Tree.png" alt="Shortest Path" style="zoom:50%;" />
- 最短路径树:所有顶点距离起始顶点路径最短
- 单元最短路径问题



对比无权图和有权图的最短路径

- 对于有权图路径的个数于路径的权值关系
- **松弛操作** Relaxation
  - 不直接到该节点是否权值更小

# Dijkstra 单元最短路径算法$O(ElogV)$ [Todo]

局限性
- 图中不能有负权值的边

> 借助最小索引堆来实现

<img src="images/Graph SP/dijkstra 01.png" alt="dijkstra 01" style="zoom:50%;" />



- 起点`0`,访问临边`0->1,0->2,0->3`,不能直接到`4`
<img src="images/Graph SP/dijkstra 01-01.png" alt="dijkstra 01-01" style="zoom:50%;" />
  - `0->1:5 `
  - `0->2:2`
  - `0->3:6 `
  - `0->4`
    - `0->2->5:2+5`
    - `0->2`是==当前==`0->4`经过过的最短路径的中间路径
> 从权值最小的边开始

- 已知从`0->2`的路径中,确定`0->2:2`为最短路径
  - 对经过`2`的从`0->{i 不等于 2}`的路径进行松弛操作
  	- `0->1:5 > 0->2->1:2+1` ,更新`0->1`最短路径
  	- `0->3:6 > 0->2->3:2+3`,更新`0->3`最短路径
<img src="images/Graph SP/dijkstra 02.png" alt="dijkstra 02" style="zoom:50%;" />
- 已知从`0->1`的路径中,`0->2->1:2+1`权值最小,确定`0->2->1:2+1`为最短路径
  - 对经过`1`的从`0->{i 不等于 1}`的路径进行松弛操作
    - `1->4:1`
      - `0->2->4:2+5 > 0->2->1->4:2+1+1`,更新`0->4`最短路径
<img src="images/Graph SP/dijkstra 04.png" alt="dijkstra 04" style="zoom:50%;" />
- 已知从`0->4`的路径中,`0->2->1->4:2+1+1`权值最小,确定`0->2->1->4:2+1+1`为最短路径
  - 从`4`不能到达任何顶点,故不需要进行松弛操作
<img src="images/Graph SP/dijkstra 05.png" alt="dijkstra 05" style="zoom:50%;" />
- 已知从`0->3`的路径中,`0->2->3:2+3`权值最小,确定`0->2->3:2+3`为最短路径
  - 对经过`3`的从`0->{i 不等于 4}`的路径进行松弛操作 ( 注:这一步没必要?`0->1`时确认了`0->4 < 0->3`,就可以跳过这一步了)
    - `0->2->3->4:2+3+2 > 0->2->1->4:2+1+1`,经过`3`的路径的权值更大不需更新
<img src="images/Graph SP/dijkstra 06.png" alt="dijkstra 06" style="zoom:50%;" />

**如何实现?**

- 找到未访问节点的最短路径
- 更新列表

使用最小索引堆`IndexMinHeap`

# 负权边

- 若图中存在负权边,"绕路"可能路径更短了
<img src="images/Graph SP/Bellman-Ford 00.png" alt="Bellman-Ford 00" style="zoom:50%;" />
<img src="images/Graph SP/Bellman-Ford 01.png" alt="Bellman-Ford 01" style="zoom:50%;" />
- 出现负权环,就不存在最短路径了
<img src="images/Graph SP/Bellman-Ford 02.png" alt="Bellman-Ford 02" style="zoom:50%;" />

# Bellman-Ford单元最短路径算法$O(EV) $[Todo]

- 图中可以有负权边,不能有负权环
- 但又可以找出负权环



如果一个图没有负权环

- 从一点到另外一点的最短路径,最多经过所有`V`个顶点,有`v-1`条边
- 否则,存在顶点经过了两次,即存在负权环,与假设矛盾



- `0`相邻的邻边
  <img src="images/Graph SP/Bellman-Ford 04.png" alt="Bellman-Ford 04" style="zoom:50%;" />
  - 对所有的点进行第1次松弛操作
    - 即找到从原点`0`开始,经过1条边的最短路径
  - 对所有的点进行第2次松弛操作
    - 即找到从原点`0`开始,经过2条边的最短路径
    - 即找到从原点`0`开始,经过另一个点到达目标点的最短路径

结论:

- 对一个点的一次松弛操作,就是找到经过这个点的另外一条路径,多一条边,权值更小.
- 如果一个图没有负权环,从一点到另外一点的最短路径,最多经过所有`V`个顶点,有`v-1`条边.若对所有点进行`V-1`次松弛操作,最后会找到该点到其他点的最短路径



Bellman-Ford单元最短路径算法的思想

- 对所有 的点进行`V-1`次松弛操作,理论上就找到了从源点到其他所有点的最短路径
- 如果还可以继续松弛,,则说明原图中有负权环

# Bellman-Ford单元最短路径算法的优化

# 更多和最短路径相关的问题

- `distTo[i]`初始化为正无穷,但具体程序中没有正无穷
- Bellman-Ford单元最短路径算法的优化:利用`queue-based bellman-ford`算法
- 对于有向无环图(DAG)使用拓扑排序

<img src="images/Graph SP/VS.png" alt="VS" style="zoom:50%;" />

- 所有对最短路径算法:任何两个顶点之间的最短路径
  - Floyd算法($O(V^3)$):处理无负权环的图
    - 使用了动态规划思想

- 最长路径算法
  - 不能有正权环
  - 无权图的最长路径问题是指数级难度的
  - 对于有权图不能使用Dijkstra算法
  - 可以使用Bellman-Ford算法