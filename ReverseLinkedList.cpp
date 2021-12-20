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
    ListNode *reverseList(ListNode *head)
    {
        return recursive(head);
    }

    ListNode *iterative(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *cur = head;

        while (head != NULL)
        {
            head = head->next;
            cur->next = prev;
            prev = cur;
            cur = head;
        }
        return prev;
    }

    ListNode *recursive(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newhead = recursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};