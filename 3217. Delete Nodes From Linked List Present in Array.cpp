#include <iostream>
#include <bits/stdc++.h>

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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {

        vector<int> rem;
        unordered_map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        ListNode *curr = head;
        int len = 0;

        while (curr != NULL)
        {

            if (mp.find(curr->val) == mp.end())
                rem.push_back(curr->val);

            curr = curr->next;
            len++;
        }

        if (rem.size() <= 0)
            return NULL;

        head = new ListNode(rem[0]);
        ListNode *newList = head;

        for (int i = 1; i < rem.size(); ++i)
        {
            newList->next = new ListNode(rem[i]);
            newList = newList->next;
        }

        return head;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Solution sl;
    vector<int> nums = {1, 3, 5};

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List: ";
    printList(head);

    Solution solution;
    ListNode *modifiedHead = solution.modifiedList(nums, head);

    cout << "Modified Linked List: ";
    printList(modifiedHead);

    return 0;

    return 0;
}