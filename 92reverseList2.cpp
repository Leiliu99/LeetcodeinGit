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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return head;
        if(m == n) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* reverseTail;
        ListNode* prevCurr;
        ListNode* nextTemp;
        int order;
        for(order = 1; order < m; order++){
            prev = curr;
            curr = curr->next;
        }
        reverseTail = curr;
        prevCurr = reverseTail;
        curr = curr->next;
        //order++;
        //cout<<order<<endl;
        while(order >= m && order < n){
            //cout<<"i"<<endl;
            nextTemp = curr->next;
            curr->next = prevCurr;
            prevCurr = curr;
            curr = nextTemp;
            order++;
        }
        if(prev == NULL && curr == NULL){
            head = prevCurr;
            reverseTail->next = curr;
            return head;
        }
        if(prev == NULL){
            head = prevCurr;
        }else{
            prev->next = prevCurr;
        }
        reverseTail->next = curr;
        return head;
    }
};