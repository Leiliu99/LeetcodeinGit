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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;//这层没有
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
         if (left > right) {//左边有右边没有
             return left + 1;//向上级返回一层
         }
         return right + 1;//右边有左边没有
         //永远返回多的那层+1
         //（左边多的加我自己or右边多的加我自己）

    }
};