/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* curr = head;
        while(curr != NULL){//clone the elements right after the node
            Node* newNode = new Node(curr->val);
            Node* temp = curr->next;
            curr->next = newNode;
            newNode->next = temp;
            curr = temp;
        }
        curr = head;
        while(curr != NULL){//clone the elements right after the node
            if(curr->random != NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        //split two lists: very important!
        curr = head;
        Node* cloneHead = curr->next;
        while(curr != NULL && curr->next != NULL){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            curr = temp; // only interative one node so two of the lists got split
        }
        return cloneHead;
    }
};