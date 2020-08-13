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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* headPtr = head;
        ListNode* newHead;
        ListNode* newHeadAfter;
        while(headPtr != NULL){
            if(headPtr == head){//first element in original linkedlist
                newHeadAfter = new ListNode(headPtr->val);
                headPtr = headPtr->next;
                continue;
            }
            newHead = new ListNode(headPtr->val, newHeadAfter);
            newHeadAfter = newHead;
            headPtr = headPtr->next;
        }
        return newHeadAfter;
    }
};
//
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* prev = NULL;
//        ListNode* curr = head;
//        while (curr != NULL) {
//            ListNode* nextTemp = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = nextTemp;
//        }
//        return prev;
//    }
//};