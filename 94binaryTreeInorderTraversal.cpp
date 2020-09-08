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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        //recursive solution
        inorderTraversalHelper(root);
        return res;
    }

    void inorderTraversalHelper(TreeNode* root){
        if(root == NULL) return;
        inorderTraversalHelper(root->left);
        res.push_back(root->val);
        inorderTraversalHelper(root->right);
    }


};

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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        //interative solution
        if(root == NULL) return res;
        stack<TreeNode*> inOrderNodeVal;
        TreeNode* curr = root;
        while(!inOrderNodeVal.empty() || curr != NULL){
            while(curr != NULL){
                inOrderNodeVal.push(curr);
                curr = curr->left;//let root pointing to the very left node
            }
            //that position would be the first element that need to be sub into my res vector
            TreeNode* targetNode = inOrderNodeVal.top();
            inOrderNodeVal.pop();//delete this node in the stack
            res.push_back(targetNode->val);
            cout<<targetNode->val<<endl;
            curr = targetNode->right;
            // if(curr != NULL){
            //     cout<<curr->val<<endl;
            // }
        }

        return res;
    }



};



