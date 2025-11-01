/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        ListNode *ans_head = NULL;
        ListNode *tail = NULL;
        ListNode *curr = head;
        while(curr){
            if(!st.count(curr->val)){
                if(!ans_head){
                    ans_head = tail = curr; 
                }else{
                    tail->next = curr;
                    tail = tail->next;
                }
            }
            curr = curr->next;
        }
        tail->next = NULL;
        return ans_head;
    }
};