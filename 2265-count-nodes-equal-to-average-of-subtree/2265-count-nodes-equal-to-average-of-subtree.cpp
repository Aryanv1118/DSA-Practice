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
    int count = 0;
    int dfs2(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return root->val+dfs2(root->left)+dfs2(root->right);
    }
    int dfs1(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1+dfs1(root->left)+dfs1(root->right);
    }
    void dfs3(TreeNode* root){
        if(root == nullptr)
            return;
        int avg;
        if(dfs1(root)){
            avg = dfs2(root)/dfs1(root);
        }
        if(root && avg == root->val){
            count++;
        }
        dfs3(root->left);
        dfs3(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        dfs3(root);
        return count;
    }
};