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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;

        ListNode* flag=&dummy;
        ListNode* ptr=head;

        while(ptr){
            if(ptr->next && ptr->val==ptr->next->val){
                while(ptr->next && ptr->next->val==ptr->val)
                    ptr=ptr->next;
                flag->next=ptr->next;
            }
            else 
                flag=flag->next;

            ptr=ptr->next;
        }
        return dummy.next;
    }
};