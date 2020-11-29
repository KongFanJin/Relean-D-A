/**
 * @file DFS.cpp
 * @author huahua
 * @brief 102. Binary Tree Level Order Traversal
 * @version 0.1
 * @date 2020-11-11
 *
 * @copyright Copyright (c) 2020
 */

#include <vector>

using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> ans;

    DFS(root, 0, ans);

    return ans;
  }

private:
  /**
   * @brief 
   * 
   * @param root 
   * @param depth 
   * @param ans 
   */
  void DFS(TreeNode *root, int depth, vector<vector<int>> &ans) {
    if (root == nullptr)
      return;

    // Works with pre/in/post order
    // 当前数组还未存储当前树层的数据,先创建空数据,用来站位
    while (ans.size() <= depth){
        ans.push_back({});
        
        DFS(root->left, depth + 1, ans);
        DFS(root->left, depth + 1, ans);
        ans[depth].push_back(root->val);
    }      
  }
};