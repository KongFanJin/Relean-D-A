/**
 * @file BFS.cpp
 * @author Huahua
 * @brief LeetCode 637. Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
		if(root == nullptr)
            	return {};
        
        vector<double> ans;
        vector<TreeNode*> curr, next;
        curr.push_back(root);

        // process every level an by one
        while(!curr.empty()){
            long long sum = 0;
            for(const auto& node : curr){
                sum += node->val;
                if(node->left)
                    next.push_back(node->left);
                if(node->right)
                    next.push_back(node->right);
            }

            ans.push_back(static_cast<double>(sum)/curr.size());
            
            // swap(curr, next);
            // movable
            curr.swap(next); 
            next.clear();
        }

        return ans;
        
    }
};