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
        if(head == NULL) return head;
        bool firstBigger = false;
        ListNode* firstBiggerNode = head;
        ListNode* prefirstBiggerNode = NULL;
        while(firstBiggerNode != NULL){
            if(firstBiggerNode->val >= x){
                firstBigger = true;
                break;
            }
            prefirstBiggerNode = firstBiggerNode;
            firstBiggerNode = firstBiggerNode->next;
        }
        if(!firstBigger) return head; //already partitioned no need to change
        ListNode* pre = firstBiggerNode;
        ListNode* curr = firstBiggerNode->next;
        while(curr != NULL){
            if(curr->val < x){
                if(prefirstBiggerNode == NULL){
                    head = curr;
                }else{
                    prefirstBiggerNode->next = curr;
                }
                pre->next = curr->next;
                prefirstBiggerNode = curr;
                curr = pre->next;
            }else{
                pre = curr;
                curr = curr->next;
            }

        }
        if(prefirstBiggerNode == NULL){
            return head;
        }else{
            prefirstBiggerNode->next = firstBiggerNode;
            return head;
        }

    }
};