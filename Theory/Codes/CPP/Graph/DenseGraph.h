#ifndef DenseGraph_h
#define DenseGraph_h

#include <cassert>
#include <vector>

using std::vector;

class DenseGraph {
private:
    // (n, m) = (顶点数, 边数)
    int n, m;
    // 用来标记是有向图,还是无向图
    bool directed;
    // 邻接矩阵
    vector<vector<bool>> g;

public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;

        for (int i = 0; i < n; ++i)
            g.push_back(vector<bool>(n, false));
    }

    ~DenseGraph(){}

    int V(){return n;}
    int M(){return m;}

    void addEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        // 判断是都已存在边
        if(hasEdge(v, w))
            return;

        g[v][w] = true;
        // 处理无向图时,要同时维护[v][w]和[w][v]
        if(!directed)
            g[w][v] = true;

        m++;
    }

    bool hasEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }

  // 通过制作Iterator访问私有数据
  class adjIterator{
    private:
      DenseGraph &G;
      int v;
      int index; // 指示当前迭代的位置
    public:
      adjIterator(DenseGraph &graph, int v): G(graph){
        this->v = v;
        this->index = -1; // 
      }

      int begin(){
          index = -1;
          return next();
      }

      int next(){
          // 若没有对index初始化为-1,会漏掉0行
          for(index += 1; index < G.V(); index ++)
            if(G.g[v][index])
                return index;
          
          return -1;
       }

      bool end(){
          return index >= G.V();
      }
  };
};

#endif