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
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0;i < qSize;i++){
                TreeNode* currNode = q.front();
                q.pop();
                if(i == qSize - 1){
                    result.push_back(currNode->val);
                }
                if(currNode->left != NULL){
                    q.push(currNode->left);
                }
                if(currNode->right != NULL){
                    q.push(currNode->right);
                }                
            }
        }
        return result;
    }
};