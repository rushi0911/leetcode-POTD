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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
        int idx=-1;
        int maxi = INT_MIN;
        int cnt=0;
        while(!q.empty()){
            int sz = q.size();
            int sum=0;
            for(int i=0;i<sz;i++){
                TreeNode *curr = q.front().first;
                int level = q.front().second;
                q.pop();
                sum+=(curr->val);
                if(curr->left){
                    q.push({curr->left,level+1});
                }
                if(curr->right){
                    q.push({curr->right,level+1});
                }
            }
            cnt++;
            // cout<<cnt<<endl;
            if(sum>maxi){
                maxi = sum;
                idx = cnt;
            }
        }
        return idx;
    }
};