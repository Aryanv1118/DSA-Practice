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
    int ans = 0;
    void dfs(TreeNode* root,int x){
        if(root == nullptr){
            return;
        }
        x = x + root->val;
        if(root->left == nullptr && root->right == nullptr){
            ans += x;
            return;
        }
        dfs(root->left,10*x);
        dfs(root->right,10*x);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};