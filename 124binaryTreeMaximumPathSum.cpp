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
    int maxSum = -INT_MAX;
    int maxPathSum(TreeNode* root) {
        maxPathSumHlper(root);
        return maxSum;
    }
    int maxPathSumHlper(TreeNode* root){
        if(root == NULL) return 0;
        int rootVal = root -> val;
        int leftSum = maxPathSumHlper(root->left);
        int rightSum = maxPathSumHlper(root->right);
        int rootPlusLeft = rootVal + leftSum;
        int rootPlusRight = rootVal + rightSum;
        int rootPlusLeftPlusRight = rootVal + leftSum + rightSum;
        //for values comparison
        //return three of these
        //one of this is only for updating global variables

        int maximumPossiblePath = max(rootVal, max(rootPlusLeft, rootPlusRight));
        int updateMaxium = max(maximumPossiblePath, rootPlusLeftPlusRight);
        if(updateMaxium > maxSum){
            maxSum = updateMaxium;
        }
        return maximumPossiblePath;

    }

};