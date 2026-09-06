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
        if(root == nullptr){
            return 0;
        }
        return 1+dfs(root->left)+dfs(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* temp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr && curr->val == x){
                    temp = curr;
                    break;
                }
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        int xsz = dfs(temp);
        int lsz = dfs(temp->left);
        int rsz = dfs(temp->right);
        int psz = n - xsz;
        return max({lsz,rsz,psz}) > n/2;
    }
};