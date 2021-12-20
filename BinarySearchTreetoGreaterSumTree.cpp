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
class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        DFStraverse(root, sum);
        return root;
    }

    void DFStraverse(TreeNode *cur, int &sum)
    {
        if (!cur)
            return;
        DFStraverse(cur->right, sum);
        sum += cur->val;
        cur->val = sum;
        DFStraverse(cur->left, sum);
    }
};