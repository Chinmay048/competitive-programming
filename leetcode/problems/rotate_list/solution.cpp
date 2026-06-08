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
     ListNode* rotateRight(ListNode* head, int k) {
        if (!head||!head->next)
            return head;
        
        ListNode* back=head;
        int length=2;
        while (back->next->next) {
            back=back->next;
            length++;
        }
        if (length<k)
            k=k%length;
        
        if (k<=0)
            return head;

        ListNode* temp;
        temp=back->next;
        temp->next=head;
        back->next=NULL;
        head=temp;
        
        return rotateRight(head,k-1);

    }
};