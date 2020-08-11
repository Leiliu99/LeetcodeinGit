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
    int traverseHelper(TreeNode* root, int value){
        if(root == NULL) return 0;
        value = value * 2 + root -> val;
        if(root->right == NULL && root->left == NULL){
            return value;
        }else{
            return traverseHelper(root->left ,value) + traverseHelper(root->right ,value);
        }


    }
    int sumRootToLeaf(TreeNode* root) {
        return traverseHelper(root, 0);

    }

};