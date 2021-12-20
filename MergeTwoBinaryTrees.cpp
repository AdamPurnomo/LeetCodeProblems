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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return DFSTraverse(root1, root2);
    }

    TreeNode *DFSTraverse(TreeNode *node1, TreeNode *node2)
    {
        int val1, val2;

        if (!node1 && !node2)
            return NULL;

        if (!node1)
            val1 = 0;
        else
            val1 = node1->val;

        if (!node2)
            val2 = 0;
        else
            val2 = node2->val;

        TreeNode *merged = new TreeNode;
        merged->val = val1 + val2;

        merged->left = DFSTraverse(node1 ? node1->left : NULL, node2 ? node2->left : NULL);
        merged->right = DFSTraverse(node1 ? node1->right : NULL, node2 ? node2->right : NULL);

        return merged;
    }
};