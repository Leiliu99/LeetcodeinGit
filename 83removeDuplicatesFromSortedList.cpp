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
        if(head == NULL || head -> next == NULL) return head;
        ListNode* testHead = head;
        int preNumber = testHead->val;
        while(testHead -> next != NULL){
            if(testHead->next->val == preNumber){
                ListNode* duplicateNode = testHead -> next;
                testHead->next = duplicateNode ->next;
                delete(duplicateNode);
                //preNumber = testHead>val;
            }else{
                testHead = testHead -> next;
                preNumber = testHead->val;
            }
        }
        return head;
    }
};