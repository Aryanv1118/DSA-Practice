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
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int target,vector<int>& curr){
        if(root == nullptr){
            return;
        }
        curr.push_back(root->val);
        int remaining = target - root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(remaining == 0){
                ans.push_back(curr);
            }
        }
        dfs(root->left,remaining,curr);
        dfs(root->right,remaining,curr);
        curr.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        dfs(root,targetSum,temp);
        return ans;
    }
};