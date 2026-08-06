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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;
       
        int cnt=0;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(!fast){
            return slow->next;
        }
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast ->next;
        }
        // if(n == 1) slow ->next = fast;;
        slow ->next = slow->next->next;
        return head;
    }
};