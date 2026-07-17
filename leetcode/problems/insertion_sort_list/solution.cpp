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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* flag=head;

        while(flag && flag->next){
            if(flag->val>flag->next->val){
                ListNode* temp=flag->next;
                if(temp->next!=nullptr)
                    flag->next=temp->next;
                else 
                    flag->next=nullptr;
                if(head->val>=temp->val){
                    temp->next=head;
                    head=temp; 
                }
                else{
                    ListNode* ptr1=head;
                    ListNode* ptr2=head->next;
                    while(ptr1!=flag){
                        if(ptr2->val>temp->val){
                            temp->next=ptr2;
                            ptr1->next=temp;
                            break;
                        }
                        else {
                            ptr1=ptr1->next;
                            ptr2=ptr2->next;
                        }
                    }
                }
            }
            else 
                flag=flag->next;
        }
        return head;
    }
};