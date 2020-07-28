/**
 * Leetcode: 110
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::pair<bool, int> DFS(TreeNode* root){
        if (!root) return {true, 0};
        
        auto leftResult = DFS(root->left);
        auto rightResult = DFS(root->right);
        
        int height = max(leftResult.second, rightResult.second)+1;
        
        if (abs(leftResult.second-rightResult.second) > 1) return {false, height};
        else return {leftResult.first&&rightResult.first, height};
    }
    
    bool isBalanced(TreeNode* root) {
        
        if (!root) return true;
        if (root && !root->left && !root->right) return true;
        
        std::pair<bool, int> leftResult{true, 0};
        std::pair<bool, int> rightResult{true, 0};
        
        leftResult = DFS(root);
        // rightResult = DFS(root->right);
        
        return leftResult.first;
        
    }
};