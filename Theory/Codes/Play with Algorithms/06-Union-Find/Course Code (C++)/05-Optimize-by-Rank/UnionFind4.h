//
// Created by liuyubobobo on 9/2/16.
//

#ifndef INC_05_OPTIMIZE_BY_RANK_UNIONFIND3_H
#define INC_05_OPTIMIZE_BY_RANK_UNIONFIND3_H

#include <cassert>

using namespace std;

// 我们的第四版Union-Find
namespace UF4 {

class UnionFind {
   private:
    int* rank;    // rank[i]表示以i为根的集合所表示的树的层数
    int* parent;  // parent[i]表示第i个元素所指向的父节点
    int count;    // 数据个数

   public:
    // 构造函数
    UnionFind(int count) {
        parent = new int[count];
        rank = new int[count];  // rank
        this->count = count;
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            rank[i] = 1;  // rank
        }
    }

    // 析构函数
    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    // 查找过程, 查找元素p所对应的集合编号
    // O(h)复杂度, h为树的高度
    int find(int p) {
        assert(p >= 0 && p < count);
        // 不断去查询自己的父亲节点, 直到到达根节点
        // 根节点的特点: parent[p] == p
        while (p != parent[p]) p = parent[p];
        return p;
    }

    // 查看元素p和元素q是否所属一个集合
    // O(h)复杂度, h为树的高度
    bool isConnected(int p, int q) { return find(p) == find(q); }

    // 合并元素p和元素q所属的集合
    // O(h)复杂度, h为树的高度
    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) return;

        // 根据树高/树层来合并集合,将矮树合并到高树上
        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[qRoot] < rank[pRoot]) {
            parent[qRoot] = pRoot;
        } else {  // rank[pRoot] == rank[qRoot]
            parent[pRoot] = qRoot; 
            rank[qRoot] += 1;  // 本来高度一样,但是合并后,高了一层
        }
    }
};
}  // namespace UF4

#endif  // INC_05_OPTIMIZE_BY_RANK_UNIONFIND3_H
