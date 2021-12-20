/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        return BFStraverse(original, cloned, target);
    }

    TreeNode *DFStraverse(TreeNode *cur_original, TreeNode *cur_clone, TreeNode *target)
    {
        if (!cur_original)
            return NULL;
        if (cur_original == target)
            return cur_clone;
        TreeNode *l = DFStraverse(cur_original->left, cur_clone->left, target);
        TreeNode *r = DFStraverse(cur_original->right, cur_clone->right, target);

        if (l == NULL)
            return r;
        else
            return l;
    }

    TreeNode *BFStraverse(TreeNode *original, TreeNode *clone, TreeNode *target)
    {
        queue<TreeNode *> q, qclone;
        q.push(original);
        qclone.push(clone);

        while (!q.empty())
        {
            //process
            TreeNode *cur = q.front();
            TreeNode *curclone = qclone.front();
            q.pop(), qclone.pop();
            if (cur == target)
                return curclone;

            //push
            if (cur)
            {
                q.push(cur->left), q.push(cur->right);
                qclone.push(curclone->left), qclone.push(curclone->right);
            }
        }
        return NULL;
    }
};
