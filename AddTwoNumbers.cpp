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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *head = NULL, *tail;
        int digit, residual = 0;

        // first n addition
        while (l1 != NULL && l2 != NULL)
        {
            digit = residual + l1->val + l2->val;
            residual = int(digit / 10);

            ListNode *temp = new ListNode();
            temp->val = digit % 10;
            temp->next = NULL;

            if (head == NULL)
            {
                head = temp;
                tail = head;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        //whatever leftover
        while (l1 != NULL)
        {
            digit = residual + l1->val;
            residual = int(digit / 10);

            ListNode *temp = new ListNode();
            temp->val = digit % 10;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            digit = residual + l2->val;
            residual = int(digit / 10);

            ListNode *temp = new ListNode();
            temp->val = digit % 10;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
            l2 = l2->next;
        }

        //final digit
        if (residual == 1)
        {
            ListNode *temp = new ListNode();
            temp->val = 1;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }

        return head;
    }
};