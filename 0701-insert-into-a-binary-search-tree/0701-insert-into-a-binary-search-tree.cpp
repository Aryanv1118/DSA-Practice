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
    TreeNode* Insert(TreeNode* root,int val){
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(root->val < val){
            root->right = Insert(root->right,val);
        }
        else{
            root->left = Insert(root->left,val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return Insert(root,val);
    }
};