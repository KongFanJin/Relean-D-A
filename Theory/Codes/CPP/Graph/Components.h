#ifndef Components_h
#define Components_h

#include <cassert>
#include <iostream>

using namespace std;

/*
 * 要点 
 * 1.连通分量的计算
 * 2.深度优先的递归的过程
 */
// 求无权图的联通分量
template <typename Graph> class Component {

private:
  Graph &G;      // 图的引用
  bool *visited; // 记录dfs的过程中节点是否被访问
  int ccount;    // 记录联通分量个数
  int *id;       // 每个节点所对应的联通分量标记

  // 图的深度优先遍历[递归]
  void dfs(int v) {
    visited[v] = true; // 遍历到v
    id[v] = ccount; 
    
    // 遍历v的临边
    typename Graph::adjIterator adj(G, v);
    for (int i = adj.begin(); !adj.end(); i = adj.next()) {
      if (!visited[i]) // 没有被访问过的点
        dfs(i); // 访问该节点
    }
  }

public:
  // 构造函数, 求出无权图的联通分量
  Component(Graph &graph) : G(graph) {
    // 算法初始化
    visited = new bool[G.V()];
    id = new int[G.V()]; // 长度为G.V()

    ccount = 0;
    for (int i = 0; i < G.V(); i++) {
      visited[i] = false; // 初始每个顶点都未被访问
      id[i] = -1;
    }

    // 求图的联通分量
    for (int i = 0; i < G.V(); i++)
      if (!visited[i]) { // 没有被访问过的点
        dfs(i);          // 进行深度优先遍历与i相连接的点
        ccount++;        // 记录连通分量,当遍历一遍时,就是一个连通分量
      }
  }

  // 析构函数
  ~Component() {
    delete[] visited;
    delete[] id;
  }

  // 返回图的联通分量个数
  int count() { return ccount; }

  // 查询点v和点w是否联通
  bool isConnected(int v, int w) {
    assert(v >= 0 && v < G.V());
    assert(w >= 0 && w < G.V());
    return id[v] == id[w];
  }
};

#endif