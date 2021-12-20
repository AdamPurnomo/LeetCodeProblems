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
    unordered_map<TreeNode *, int> map;
    int rob(TreeNode *root)
    {
        if (!root)
            return 0;
        if (map[root])
            return map[root];

        //from current node and grandschildren
        int leftgc = 0, rightgc = 0;
        if (root->left)
            leftgc = rob(root->left->left) + rob(root->left->right);
        if (root->right)
            rightgc = rob(root->right->left) + rob(root->right->right);
        int grandchildMoney = root->val + leftgc + rightgc;

        //from children
        int childMoney = rob(root->left) + rob(root->right);

        map[root] = max(grandchildMoney, childMoney);

        return map[root];
    };
};