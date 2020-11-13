#ifndef ReadGraph_h
#define ReadGraph_h

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// 读取图算法
// 可同时处理稀疏图和稠密图
template <typename Graph> 
class ReadGraph {
public:
  // 从文件filename中读取图的信息, 存储进图graph中
  ReadGraph(Graph &graph, const string &filename) {

    ifstream file(filename);
    string line;
    int V, E;

    // 判断成功打开文件
    assert(file.is_open());

    // 第一行读取图中的节点个数和边的个数
    assert(getline(file, line));
    stringstream ss(line);
    ss >> V >> E;

    // 判断文件读取的顶点数与图实际的顶点数是否一致
    assert(V == graph.V());

    // 读取每一条边的信息
    for (int i = 0; i < E; i++) {
      assert(getline(file, line));
      stringstream ss(line);

      int a, b;

      ss >> a >> b;
      assert(a >= 0 && a < V);
      assert(b >= 0 && b < V);
      graph.addEdge(a, b);
    }
  }
};

#endif