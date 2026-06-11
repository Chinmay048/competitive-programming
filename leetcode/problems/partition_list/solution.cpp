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
    ListNode* partition(ListNode* head, int x) {
        ListNode right(0);
        ListNode left(0);
        
        ListNode* ptr1=&left;
        ListNode* ptr2=&right;
        ListNode* curr=head;

        while(curr){
            if(curr->val<x){
                ptr1->next=curr;
                ptr1=ptr1->next;
            }
            else{
                ptr2->next=curr;
                ptr2=ptr2->next;
            }
            curr=curr->next;
        }
        ptr2->next=NULL;
        ptr1->next=right.next;


        return left.next;
    }
};