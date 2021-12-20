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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *tail = head;
        ListNode *mid = head;
        int i = 0;
        while (tail != NULL && tail->next != NULL)
        {
            tail = tail->next->next;
            mid = mid->next;
        }

        return mid;
    }
};