#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        if (head == NULL)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};

int main()
{

    ListNode *head = new ListNode(3);
    ListNode *first = new ListNode(0);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(-4);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = first;

    Solution sl;

    cout << sl.hasCycle(head);

    return 0;
}