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
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, root->val, result);
        return result;
    }
    
    void dfs(TreeNode* root, int currMax, int &result){
        if(root == NULL){
            return;
        }
        if(root->val >= currMax){
            result++;
            currMax = root->val;
        }
        dfs(root->left, currMax, result);
        dfs(root->right, currMax, result);
    }
};