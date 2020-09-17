/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return root;
        stack<TreeNode*> nodeStack;
        TreeNode* curr = root;
        int preNodeVal = 0;
        while(!nodeStack.empty() || curr != NULL){
            while(curr != NULL){
                nodeStack.push(curr);
                curr = curr->right;//traverse to the very right node

            }
            TreeNode* targetNode = nodeStack.top();//the very right node that need to be analyzed
            nodeStack.pop();
            targetNode->val = targetNode->val + preNodeVal;
            preNodeVal = targetNode->val;
            //cout<<preNodeVal<<endl;
            curr = targetNode->left;

        }
        return root;
    }
};