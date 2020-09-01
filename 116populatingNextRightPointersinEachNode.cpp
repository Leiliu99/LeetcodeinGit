/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->right == NULL) return root;
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            int levelNodeLength = nodeQueue.size();//how many nodes in this level
            for(int i = 0; i < levelNodeLength; i++){
                Node* levelNode = nodeQueue.front();
                //cout<<levelNode->val<<endl;
                nodeQueue.pop();
                if(i != levelNodeLength-1){//not the last node in this level
                    //should point the next pointer to the next right node
                    levelNode->next = nodeQueue.front();
                }
                if(levelNode->right != NULL){
                    nodeQueue.push(levelNode->left);
                     nodeQueue.push(levelNode->right);

                }
            }
        }
        return root;
    }
};
//save a previous pointer
//Node* level_start = root;
//        while(level_start!=NULL){
//            //curr is the first node in that level
//            Node* curr = level_start;
//
//            //Keep going to the right in that level
//            while(curr!=NULL)
//            {
//                if(curr->left!=NULL) curr->left->next=curr->right;
//                if(curr->right!=NULL && curr->next!=NULL) curr->right->next=curr->next->left;
//
//                curr = curr->next;
//            }
//            level_start=level_start->left;
//        }
//        return root;