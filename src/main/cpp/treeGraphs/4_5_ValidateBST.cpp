/** Leetcode 98
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
    std::vector<int> nodes;
    
    // Helper Function  - called inside isValidBST()
    void InOrderTraversal(TreeNode* root){
        
        // Base Condition
        if (root == NULL) return;
        
        // Left
        if (root->left){
            InOrderTraversal(root->left);
        }

        // Parent
        nodes.push_back(root->val);

        // Right
        if (root->right){
            InOrderTraversal(root->right);
        }

    }
    
    bool isValidBST(TreeNode* root) {
        
        // Traverse the tree in InOrder Fashion and push back into the vector
        InOrderTraversal(root);
        
        // Check if the vector is sorted
        for (int i = 1; i < nodes.size(); i++){
            if (nodes[i] <= nodes[i-1]){
                return false;
            }
        }
        
        // Return the result
        return true;
    }
};