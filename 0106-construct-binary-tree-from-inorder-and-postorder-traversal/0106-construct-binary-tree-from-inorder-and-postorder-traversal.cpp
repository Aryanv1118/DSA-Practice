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
    unordered_map<int,int>mp;
    TreeNode* build(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int postStart,int postEnd){
        if(inStart > inEnd || postStart > postEnd)
            return nullptr;
        int rootVal = postorder[postEnd];
        TreeNode* node = new TreeNode(rootVal);
        int rootIdx = mp[rootVal];
        int re = inEnd-rootIdx;
        node->left = build(inorder,inStart,rootIdx-1,postorder,postStart,postEnd-re-1);
        node->right = build(inorder,rootIdx+1,inEnd,postorder,postEnd-re,postEnd-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return build(inorder,0,n-1,postorder,0,n-1);
    }
};