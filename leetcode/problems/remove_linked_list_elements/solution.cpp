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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* ptr=&dummy;
        while(ptr->next){
            if(ptr->next->val==val){
                if(ptr->next->next)
                    ptr->next=ptr->next->next;
                else 
                    ptr->next=NULL;
            }
            else 
                ptr=ptr->next;
        }
        return dummy.next;
    }
};