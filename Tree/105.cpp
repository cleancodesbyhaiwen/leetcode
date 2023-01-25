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
    TreeNode* addNodes(vector<int>& preorder, vector<int>& inorder, int &index, int i, int j){   
        if(i > j){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        
        int partition = 0;
        for(int i = 0;i < inorder.size();i++){
            if(inorder[i] == preorder[index]){
                partition = i;
                break;
            }
        }
        index++;
        root->left = addNodes(preorder, inorder, index, i, partition-1);
        root->right = addNodes(preorder, inorder, index, partition+1, j);
        return root;
    }

    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return addNodes(preorder, inorder, index, 0, preorder.size()-1);
    }
};