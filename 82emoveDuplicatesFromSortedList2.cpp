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
        if(head == NULL ) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        int removeVal;
        while(head->next != NULL && head->next->next != NULL){
            if(head->next->val == head->next->next->val){
                removeVal = head->next->val;//record the values being deleted
                while(head->next != NULL && head->next->val == removeVal){
                    head->next = head->next->next;//continue deleting
                }
            }else{
                head = head->next; //it means the previous two did not equal
            }
        }
        return dummy->next;

    }
};