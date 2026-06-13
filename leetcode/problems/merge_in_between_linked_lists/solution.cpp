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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
       ListNode* front=list1; 
       ListNode* tail=list1;
       ListNode* ptr=list2;
       
       int diff=b+1-(a-1);
       //Giving tail the start with the difference of a and b  
       while(diff>0){
        tail=tail->next;
        diff--;
       }
       //List 2 end node 
       while(ptr->next){
        ptr=ptr->next;
       }
        //Iterating both the pointer to right position 
       for(int i=1;i<a && front && tail->next;i++){
        front=front->next;
        tail=tail->next;
       }
        //Replacing the pointer 
       front->next=list2;
       ptr->next=tail;
       return list1;
    }
};