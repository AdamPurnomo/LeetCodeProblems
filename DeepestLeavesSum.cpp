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
    int count, maxlevel;

    int deepestLeavesSum(TreeNode *root)
    {
        count = 0;
        DFScount(root, 0);
        return count;
    }

    void DFScount(TreeNode *root, int level)
    {
        if (!root)
            return;                      //curret root is null
        if (!root->right && !root->left) //found leave nodes
            if (level > maxlevel)
                count = root->val, maxlevel = level; //found deeper level
            else if (level == maxlevel)
                count += root->val;

        DFScount(root->left, level + 1);
        DFScount(root->right, level + 1);
    }

    int EffBFScount(TreeNode *root)
    {
        int count, sz;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            count = 0, sz = size(q);
            for (int i = 0; i < sz; i++)
            {
                TreeNode *dummy = q.front();
                q.pop();
                count += dummy->val;
                if (dummy->left)
                    q.push(dummy->left);
                if (dummy->right)
                    q.push(dummy->right);
            }
        }

        return count;
    }

    int BFScount(TreeNode *root)
    {
        queue<TreeNode *> q;
        queue<int> nodelevel;
        int count = 0, maxlevel = 0;
        q.push(root);
        nodelevel.push(1);

        while (!q.empty())
        {
            //process the current node
            int curlevel = nodelevel.front();
            if (curlevel > maxlevel)
            {
                maxlevel = curlevel;
                count = q.front()->val;
            }
            else
                count += q.front()->val;

            //push to the queue if valid node
            if (q.front()->left != NULL)
            {
                q.push(q.front()->left);
                nodelevel.push(curlevel + 1);
            }
            if (q.front()->right != NULL)
            {
                q.push(q.front()->right);
                nodelevel.push(curlevel + 1);
            }

            nodelevel.pop();
            q.pop();
        }

        return count;
    }
};