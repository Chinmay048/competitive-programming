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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        } 
        else if (!head->next->next) {
            head->next = NULL;
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next) {
            if(fast->next->next==NULL)
                fast=fast->next;
            else 
                fast=fast->next->next;
            slow=slow->next;
        }
        slow->val = slow->next->val;
        slow->next = slow->next->next;

        return head;
    }
};