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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* mid = findMiddle(head);
        ListNode* tail = reverseList(mid->next);
        mid->next = NULL;
        head = mergeTwoLists(head, tail);
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp;
        while(head != NULL){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode* mergeTwoLists(ListNode* head, ListNode* tail){
        ListNode* l1 = head;
        ListNode* l2 = tail;
        ListNode* dummy = new ListNode(0);
        ListNode* dummyHead = dummy;
        bool toggle = true;
        while(l1 != NULL || l2 != NULL){
            if(toggle){
                dummy->next = l1;
                l1 = l1->next;
            }else{
                dummy->next= l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
            toggle = !toggle;
        }
        while(l1 != NULL){
            dummy->next = l1;
            dummy = dummy->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            dummy->next = l2;
            dummy = dummy->next;
            l2 = l2->next;
        }
         ListNode* res = dummyHead->next;
        delete(dummyHead);
        return res;

    }

};