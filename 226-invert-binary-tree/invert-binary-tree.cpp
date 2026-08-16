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
    void invert(TreeNode *root){
        if(!root) return ;
        TreeNode* root_left = root->left;
        root->left = root->right;
        root->right = root_left;
        invert(root->left);
        invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        invert(root);
        return root;
    }
};