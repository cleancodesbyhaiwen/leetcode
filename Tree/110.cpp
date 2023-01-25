/**
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
    bool dfs(TreeNode* root, int& height){
        if(root == NULL){
            height = -1;
            return true;
        }
        
        int leftHeight = 0;
        int rightHeight = 0;
        
        if(!dfs(root->left, leftHeight) || !dfs(root->right, rightHeight)){
            return false;
        }
        if(abs(leftHeight-rightHeight) > 1){
            return false;
        }
        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
    
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }
};