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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>> levelOrderRes = levelOrder(root);
         vector<vector<int>> res = reverse(levelOrderRes);
         return res;
    }
    vector<vector<int>> reverse(vector<vector<int>> original){
         for(int i = 0, j = original.size()-1; i < j; i++, j--){
             vector<int> temp = original[i];
             original[i] = original[j];
             original[j] = temp;
         }
        return original;

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> nodeRecord;
        if(root == NULL) return res;
        nodeRecord.push(root);
        while(nodeRecord.size() > 0){
            vector<int> level;//a new vector for new level
            int nodeLength = nodeRecord.size();
            for(int i = 0; i < nodeLength; i++){//push all the elements in this level
                TreeNode* levelNode = nodeRecord.front();
                nodeRecord.pop();
                level.push_back(levelNode->val);
                if(levelNode->left != NULL){
                    nodeRecord.push(levelNode->left);
                }
                if(levelNode->right != NULL){
                    nodeRecord.push(levelNode->right);
                 }

            }
            res.push_back(level);//append this level to final result within as one vector

        }

        return res;
    }
};