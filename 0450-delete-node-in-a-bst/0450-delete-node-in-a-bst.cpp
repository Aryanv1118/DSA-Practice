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
    TreeNode* findMin(TreeNode* root){
        while(root->left != nullptr)
            root = root->left;
        return root;
    }
    TreeNode* deletion(TreeNode* root,int key){
        if(root == nullptr)
            return  root;
        if(key < root->val)
            root->left = deletion(root->left,key);
        else if(key > root->val)
            root->right = deletion(root->right,key);
        else{
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            if(root->left == nullptr || root->right == nullptr){
                if(root->left!=nullptr){
                    TreeNode* Temp = root->left;
                    delete root;
                    return Temp;
                }
                if(root->right!=nullptr){
                    TreeNode* Temp = root->right;
                    delete root;
                    return Temp;
                }       
            }
            else{
                TreeNode* node = findMin(root->right);
                root->val = node->val;
                root->right = deletion(root->right,node->val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletion(root,key);
    }
};