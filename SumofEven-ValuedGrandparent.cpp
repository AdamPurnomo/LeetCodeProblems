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
    int sumEvenGrandparent(TreeNode *root)
    {
        return DFStraverse(root, NULL, NULL);
    }

    int DFStraverse(TreeNode *cur, TreeNode *parent, TreeNode *grandparent)
    {
        int sum = 0;
        if (!cur)
            return 0;
        if (grandparent != NULL && grandparent->val % 2 == 0)
            sum += cur->val;
        int l = DFStraverse(cur->left, cur, parent);
        int r = DFStraverse(cur->right, cur, parent);
        return sum + r + l;
    }
};