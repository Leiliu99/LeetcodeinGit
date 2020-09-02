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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true; //if the linked list is empty or only has one node, it is palindrome
        //first find the middle point in the palindrome
        ListNode* mid = head;
        ListNode* midHelper = head->next;
        while(midHelper != NULL && midHelper->next != NULL){
            midHelper = midHelper->next->next;
            mid = mid->next;
        }
        ListNode* secondHalfHead = reverseList(mid->next);
        ListNode* firstHalfHead = head;
        while(secondHalfHead != NULL){
            if(firstHalfHead->val != secondHalfHead->val){
                return false;
            }
            firstHalfHead = firstHalfHead->next;
            secondHalfHead = secondHalfHead->next;
        }
        return true;
    }

     ListNode* reverseList(ListNode* head){
         if(head == NULL || head->next == NULL) return head;// no need to reverse
         ListNode* pre = NULL;
         ListNode* curr = head;
         while(curr != NULL){
            ListNode* temp = curr->next;
             curr->next = pre;
             pre = curr;
             curr = temp;
         }
         return pre;
     }
};