#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {

        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        ListNode *current = head, *prev = NULL;
        int count = 1;

        while (count != left)
        {

            prev = current;
            current = current->next;
            count++;
        }

        ListNode *start = current;
        while (count != right)
        {
            current = current->next;
            count++;
        }

        ListNode *rest = current->next;
        current->next = NULL;

        ListNode *newHead = reverse(start);

        if (prev != NULL)
        {
            prev->next = newHead;
        }
        current = newHead;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = rest;
        if (left == 1)
        {
            return newHead;
        }
        else
        {
            return head;
        }
    }
};