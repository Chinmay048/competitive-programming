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
    ListNode* mergeNodes(ListNode* head) {
        head=head->next;
        ListNode* main=head;
        ListNode* ptr=head; 
        int sum=0;
        while(ptr){
            if(ptr->val==0){
                main->val=sum;
                if(!ptr->next){
                    main->next=NULL;
                    main=main->next;
                }
                else 
                    main=main->next;
                sum=0;
            }
            else sum+=ptr->val;
            ptr=ptr->next;
        }        
        return head;


    }
};