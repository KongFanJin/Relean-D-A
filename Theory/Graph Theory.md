# Concept

- Vertex
- Edge




应用
- 交通运输
- 社交网络
- 互联网
- 工作安排
- 程序状态
  - 自动机




- Undirected Graph & Directed Graph

- Unweighted Graph & Weighted Graph



图的连通性



Simple Graph

- self-loop & parallel-edges
  - 不影响图的连通性

# 图的表示

## Adjacency matrix
- 无向图
<img src="images/Graph/AdMatrix-1.png" alt="AdMatrix" style="zoom:50%;" />
- 有向图
<img src="images/Graph/AdMatrix-2.png" alt="AdMatrix-2" style="zoom:50%;" />

- 邻接矩阵适合表示稠密图(Dense Graph)
<img src="images/Graph/Dense Graph.png" alt="Dense Graph" style="zoom:50%;" />

## Adjacency List
<img src="images/Graph/AdjacencyLists-1.png" alt="AdjacencyLists-1" style="zoom:50%;" />

- 邻接表适合用来表示稀疏图(Sparse Graph)
  - 每个顶点与其他顶点连接的边少于顶点总数
<img src="images/Graph/Sparse Graph.png" alt="Sparse Graph" style="zoom:50%;" />

# 遍历临边
<img src="images/Graph/Traverse.png" alt="Traverse" style="zoom: 50%;" />
邻接矩阵`g[v][w]`
- `g[v][i]`,遍历行
邻接表
- `g[v]`,查表即可
