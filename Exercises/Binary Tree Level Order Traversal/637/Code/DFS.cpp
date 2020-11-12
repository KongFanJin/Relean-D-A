/**
 * @file DFS.cpp
 * @author Huahua
 * @brief LeetCode 637. Average of Levels in Binary Tree
 * @version 0.1
 * @date 2020-11-11
 *
 * @copyright Copyright (c) 2020
 */

#include <vector>

using std::pair;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    if (root == nullptr)
      return {};

    /**
     * @brief sum_count[depth], pair<sum, count>
     */
    vector<pair<long long, int>> sum_count;
    vector<double> ans;

    preorder(root, 0, sum_count);

    for (const auto &p : sum_count)
      ans.push_back(static_cast<double>(p.first) / p.second);
    return ans;
  }

private:
  /**
   * @brief
   *
   * @param root
   * @param depth
   * @param sum_count
   */
  void preorder(TreeNode *root, int depth,
                vector<pair<long long, int>> &sum_count) {
    if (root == nullptr)
      return;

    // sum_count第一次使用时未被初始化,此处相当于对其进行初始化
    // 如果采用中序遍历,需要使用while,注:未理解
    if (depth >= sum_count.size())
      sum_count.push_back({0, 0});

    sum_count[depth].first += root->val; // 累加来获得树层的和
    ++sum_count[depth].second;           // 计数树层的节点

    preorder(root->right, depth + 1, sum_count);
    preorder(root->left, depth + 1, sum_count);
  }
};