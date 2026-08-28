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
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int sum = 0;
        if(root->left && !root->left->left && !root->left->right){
            sum += root->left->val;
        }
        return sum+dfs(root->left)+dfs(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
       return dfs(root);
    }
};