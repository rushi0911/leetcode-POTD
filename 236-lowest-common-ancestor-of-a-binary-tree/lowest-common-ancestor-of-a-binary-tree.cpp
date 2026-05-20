/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode *lft = lowestCommonAncestor(root->left,p,q);
        TreeNode *rgt = lowestCommonAncestor(root->right,p,q);
        if(lft && rgt){
            return root;
        }
        if(lft){
            return lft;
        }
        if(rgt){
            return rgt;
        }
        return NULL;
    }
};