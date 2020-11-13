#ifndef SpaarseGraph_h
#define SpaarseGraph_h

#include <cassert>
#include <vector>

using std::vector;

class SparseGraph {
private:
  int n, m;
  bool directed;
  vector<vector<int>> g; // vector删除节点并不方便

public:
  SparseGraph(int n, bool directed) {
    this->n = n;
    this->m = 0;
    this->directed = directed;
    for (int i = 0; i < n; i++)
      g.push_back(vector<int>());
  }

  ~SparseGraph() {}

  int V() { return n; }
  int M() { return m; }
  
  // O(n) 
  // 当前忽略平行边
  void addEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);

    g[v].push_back(w);
    // 处理无向图时,要同时维护[v][w]和[w][v]
    // 处理自环边v != w
    if (v != w && !directed)
      g[w].push_back(v);

    m++;
  }

  bool hasEdge(int v, int w){
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);

    for(int i = 0; i  < g[v].size(); i++)
        if(g[v][i] == w)
          return true;
    
    return false;
  }

  // 通过制作Iterator访问私有数据
  class adjIterator{
    private:
      SparseGraph &G;
      int v;
      int index; // 指示当前迭代的位置
    public:
      adjIterator(SparseGraph &graph, int v): G(graph){
        this->v = v;
        this->index = 0;
      }

      int begin(){
        index = 0;
        if(G.g[v].size())
          return G.g[v][index];
        return -1;
      }

      int next(){
        index ++;
        if(index < G.g[v].size())
          return G.g[v][index];
        return -1;
      }

      bool end(){
        return index >= G.g[v].size();
      }
  };
};

#endif