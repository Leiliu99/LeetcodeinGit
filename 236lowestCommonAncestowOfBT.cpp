/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        if(root == p || root == q) return root;
        //Two circumstances for base case, root is NULL or root is the target child
        //divide
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //conquer
        if(left != NULL && right != NULL){
            return root;//this root has left target child and right target child-> the target ancestor
        }else if(left != NULL){
            return left;//this root only has one child
        }else if(right != NULL){
            return right;
        }else{
            //this root does not have child
            return NULL;
        }
    }
};