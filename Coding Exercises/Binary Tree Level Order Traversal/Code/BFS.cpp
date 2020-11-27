/**
 * @file BFS.cpp
 * @author huahua
 * @brief 102. Binary Tree Level Order Traversal
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 */

#include<vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		if(root == nullptr)
            return {};
        
        vector<vector<int>> ans;
        vector<TreeNode*> curr, next;

        curr.push_back(root);

        // process every level an by one
        while(!curr.empty()){
            ans.push_back({});
            for(const auto& node : curr){
                ans.back().push_back(node->val); // 取末尾数组,然后加进去

                if(node->left)
                    next.push_back(node->left);
                if(node->right)
                    next.push_back(node->right);
            }
            
            // swap(curr, next);
            // movable
            curr.swap(next); 
            next.clear();
        }

        return ans;
    }
};