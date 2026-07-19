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
    int count  = 0;
    int dfs(TreeNode* root){
        if(root == nullptr)
            return 0;
        if(root->left == nullptr &&& root->right == nullptr)
            count++;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(root->val >= l && root->val >= r){
            count++;
        }
        return max(root->val,max(l,r));
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return count;
    }
};