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
    int dfs(TreeNode*root){
        if(root == nullptr){
            return 0;
        }
        int lst = dfs(root->left);
        int rst = dfs(root->right);
        if(root->left == nullptr)
            return rst + 1;
        if(root->right == nullptr)
            return lst+1;
        return 1+min(lst,rst);
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};