#include <bits/stdc++.h>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *tail = head;
        ListNode *delay = head;

        //initialize distance
        int i = 0;
        while (i < n)
        {
            tail = tail->next;
            i++;
        }

        if (tail == NULL)
        {
            head = head->next;
            return head;
        }

        // increase one by one
        while (tail->next != NULL)
        {
            tail = tail->next;
            delay = delay->next;
        }

        delay->next = delay->next->next;
        return head;
    }
};