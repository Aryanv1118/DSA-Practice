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
    unordered_map<int,int> mp;
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }
        int rootVal = preorder[preStart];
        TreeNode* node = new TreeNode(rootVal);
        int rootIndex = mp[rootVal];
        int ls = rootIndex-inStart;
        node->left = build(preorder,preStart+1,preStart+ls,inorder,inStart,rootIndex-1);
        node->right = build(preorder,preStart+ls+1,preEnd,inorder,rootIndex+1,inEnd);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,0,n-1,inorder,0,n-1);
    }
};