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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* insertNode = new TreeNode(val);
            return insertNode;
        }
        insertIntoBSTHelper(root, val);
        return root;
    }
    void insertIntoBSTHelper(TreeNode* curr, int val){
        if(curr->val > val){
             if(curr->left == NULL){
                 TreeNode* insertNode = new TreeNode(val);
                 curr->left = insertNode;
                 return;
             }else{
                 return insertIntoBSTHelper(curr->left, val);
             }
        }else{
             if(curr->right == NULL){
                 TreeNode* insertNode = new TreeNode(val);
                 curr->right = insertNode;
                 return;
             }else{
                 return insertIntoBSTHelper(curr->right, val);
             }
        }
    }
};