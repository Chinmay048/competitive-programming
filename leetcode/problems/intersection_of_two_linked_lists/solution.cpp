/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA=headA;
        ListNode* ptrB=headB;

        while(ptrA!=ptrB){
            if(ptrA)
                ptrA=ptrA->next;
            else 
                ptrA=headA;
            if(ptrB)
                ptrB=ptrB->next;
            else 
                ptrB=headB;
        }
        return ptrA;
        
    }
};