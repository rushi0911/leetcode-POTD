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
    bool checkSameTree(TreeNode *p, TreeNode *q){
        if(!p || !q) return p==q;
        if(p->val != q->val) return false;
        return ((p->val == q->val) && checkSameTree(p->left,q->left) && checkSameTree(p->right,q->right));
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSameTree(p,q);
    }
};