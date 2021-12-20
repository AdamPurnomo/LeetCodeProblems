/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/* DFS can be used bot using postorder traversal */

class Solution
{
public:
    Node *connect(Node *root)
    {
        BFSTraverse(root);
        return root;
    }

    void BFSTraverse(Node *cur)
    {
        Node *head = cur, *tail = NULL;

        while (cur)
        {
            if (cur->left)
            {
                if (tail)
                    tail->next = cur->left, tail = tail->next;
                else
                    tail = cur->left, head = tail; // this part only for the initialization once reaching a new level
            }

            if (cur->right)
            {
                if (tail)
                    tail->next = cur->right, tail = tail->next;
                else
                    tail = cur->right, head = tail;
                ; // this part only for the initialization once reaching a new level if left nonexistent
            }

            cur = cur->next;
            if (!cur)
            {
                cur = head;
                head = NULL;
                tail = NULL;
            }
        }
    }

    void DFStraverse(Node *cur)
    {
        if (!cur)
            return;
        if (cur->left)
            cur->left->next = cur->right ? cur->right : search(cur->next);
        if (cur->right)
            cur->right->next = search(cur->next);

        DFStraverse(cur->right ? cur->right : NULL);
        DFStraverse(cur->left ? cur->left : NULL);
    }

    Node *search(Node *cur)
    {
        while (cur)
        {
            if (cur->left)
                return cur->left;
            else if (cur->right)
                return cur->right;
            cur = cur->next;
        }
        return NULL;
    }
};