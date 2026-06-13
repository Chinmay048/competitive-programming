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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
      
        ListNode* ptr=head;
        while(ptr && ptr->next){
            int a=ptr->val,b=ptr->next->val;
            while(b!=0){
                int temp=b;
                b=a%b;
                a=temp;
            }
            ListNode* temp=new ListNode(a);
            temp->next=ptr->next;
            ptr->next=temp;
            ptr=ptr->next->next;
        }
        return head;

    }
};