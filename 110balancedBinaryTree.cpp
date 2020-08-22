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
    //bool isBalanced = true;
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int leftLevel = maxiumDepthOfTree(root->left);
        int rightLevel = maxiumDepthOfTree(root->right);
        if(leftLevel == -1 || rightLevel == -1) return false;//already inbalanced
        int difference = abs(leftLevel - rightLevel);
        cout<<rightLevel<<endl;
        cout<<leftLevel<<endl;
        return (difference < 2);
    }

    int maxiumDepthOfTree(TreeNode* root){
        if(root == NULL) return 0;
        int leftDepth = maxiumDepthOfTree(root->left);
        int rightDepth = maxiumDepthOfTree(root->right);
        if(leftDepth == -1 || abs(leftDepth - rightDepth) >= 2 || rightDepth == -1) return -1; //if one of the subtree is unblanced or this one is inbalanced
        if(leftDepth > rightDepth){
            return leftDepth + 1;
        }else{
            return rightDepth + 1;
        }
    }
};