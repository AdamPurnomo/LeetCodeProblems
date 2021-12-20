/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *c = head->next, *n = c->next;
        vector<int> res = {-1, -1};

        int prevval, curval, nextval;
        int l_pos = -1, p_pos;
        int i = 1;
        int max_dist, min_dist = INT_MAX;

        // initialize head node
        prevval = head->val;

        while (n != NULL)
        {
            // check if current node is critical point
            nextval = n->val;
            curval = c->val;

            if (((curval < nextval) && (curval < prevval)) || ((curval > nextval) && (curval > prevval)))
            {
                if (l_pos == -1)
                {
                    l_pos = i;
                    p_pos = i;
                }
                else
                {
                    max_dist = i - l_pos;
                    if (i - p_pos < min_dist)
                        min_dist = i - p_pos;
                    p_pos = i;
                    res[0] = min_dist;
                    res[1] = max_dist;
                }
            }

            //update position
            prevval = c->val;
            c = n;
            n = c->next;
            i++;
        }

        return res;
    }
};