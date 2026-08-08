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
    ListNode *reverseLL(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = head;
        ListNode *tail = head1;
        ListNode *temp = head1;
        head1 = head1->next;
        ListNode *head2 = slow->next;
        slow->next = NULL;
        head2 = reverseLL(head2);
        bool flag = true;
        while(head1 && head2){
            if(flag){
                ListNode *next = head1;
                tail->next = head2;
                tail = head2;
                head2 = head2 -> next;
                tail->next = head1;
                flag = false;
            }else{
                ListNode *next = head2;
                tail -> next = head1;
                tail = head1;
                head1 = head1 -> next;
                tail->next = head2;
                flag = true;
            }
        }
        // cout<<tail->val<<endl;
    }
};