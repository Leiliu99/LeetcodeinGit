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
    priority_queue <int, vector<int>, greater<int>> allElements;
    void kthHelper(TreeNode* root){
        if(root == NULL) return;
        allElements.push(root->val);
        kthHelper(root->left);
        kthHelper(root->right);
    }


    int kthSmallest(TreeNode* root, int k) {
        kthHelper(root);

        for(int i = 0; i < k - 1; i++){
            //cout<<allElements.top()<<endl;
            allElements.pop();
        }
        return allElements.top();
    }
};