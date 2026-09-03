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
    vector<int>tree;
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        dfs(root->left);
        tree.push_back(root->val);
        dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int l = 0;
        int r = tree.size()-1;
        while(l<r){
            int sum = tree[l]+tree[r];
            if(sum == k)
                return true;
            else if(sum < k)
                l++;
            else
                r--;
        }
        return false;
    }
};