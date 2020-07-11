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
    int getDecimalValue(ListNode* head) {
         int ret = 0;
        while(head)
        {
            ret <<= 1;//right shift one position
            ret |= head->val;//OR with new value VERY SMART!!
            head = head->next;
        }
        return ret;//directly return(???)

    }
};

//class Solution {
//public:
//    int getDecimalValue(ListNode* head) {
//        vector<int> binNumber;
//        while(head != nullptr){
//            //cout<<head->val<<endl;
//            binNumber.push_back(head->val);
//            head = head->next;
//        }
//
//        int res = 0;
//        int index = 0;
//        for(int i = binNumber.size() - 1; i >= 0; i--){
//            int portion =  binNumber[i] * pow(2, index);
//            res += portion;
//            index++;
//        }
//        return res;
//
//    }
//};
